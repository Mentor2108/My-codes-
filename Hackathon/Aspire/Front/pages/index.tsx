import { Box, Stack } from "@chakra-ui/layout";
import dynamic from "next/dynamic";
import NodeModal from "../components/NodeModal";
import { useState, useEffect } from "react";
import {
  CustomNodeElementProps,
  RawNodeDatum,
  TreeNodeDatum,
} from "react-d3-tree/lib/types/common";
import { v4 } from "uuid";

const Tree = dynamic(() => import("react-d3-tree"), {
  ssr: false,
});


async function componentDidMount() {
  try {
    const response = await fetch("http://localhost:8000/SkillTree/generatedata?name=Web Development");
  } catch(e) {
    console.log(e)
  }
}


export function bfs(
  id: string,
  tree: RawNodeDatum | RawNodeDatum[],
  node: RawNodeDatum
) {
  const queue: RawNodeDatum[] = [];

  queue.unshift(tree as RawNodeDatum);

  while (queue.length > 0) {
    const curNode = queue.pop();

    if (curNode.attributes?.id === id) {
      curNode.children.push(node);

      return { ...tree };
    }

    const len = curNode.children.length;

    for (let i = 0; i < len; i++) {
      queue.unshift(curNode.children[i]);
    }
  }
}



export default function Home() {
  componentDidMount()
  var res = require("/home/mentor/Documents/Coding/My-codes-/Hackathon/Aspire/Django/sample.json");
  const [tree, setTree] = useState<RawNodeDatum | RawNodeDatum[]>(res);
  const [node, setNode] = useState<TreeNodeDatum | undefined>();

  const close = () => setNode(undefined);

  const handleNodeClick = (datum: TreeNodeDatum) => {
    setNode(datum);
  };

  const handleSubmit = (familyMemberName: string) => {
    const newTree = bfs(node.attributes?.id, tree, {
      name: familyMemberName,
      attributes: {
        id: v4(),
      },
      children: [],
    });

    if (newTree) {
      setTree(newTree);
    }

    setNode(undefined);
  };

  const renderRectSvgNode = (
    customProps: CustomNodeElementProps,
    click: (datum: TreeNodeDatum) => void
  ) => {
    const { nodeDatum } = customProps;

    return (
      <g>
        <circle r="15" fill={"#777"} onClick={() => click(nodeDatum)} />
        <text fill="black" strokeWidth="0.5" x="20" y="-5">
          {nodeDatum.name}
        </text>
      </g>
    );
  };

  return (
    <Stack direction="row" spacing="md">
      <Box w="100%" h="100vh">
        <Tree
          data={tree}
          zoomable={true}
          onNodeClick={handleNodeClick}
          translate={{
            x: 200,
            y: 200,
          }}
          renderCustomNodeElement={(nodeInfo) =>
            renderRectSvgNode(nodeInfo, handleNodeClick)
          }
        />
        <NodeModal
          onSubmit={(familyMemberName) => handleSubmit(familyMemberName)}
          onClose={close}
          isOpen={Boolean(node)}
        />
      </Box>
    </Stack>
  );
}

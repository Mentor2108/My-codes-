import React from 'react';
import { Tree, TreeNode } from 'react-organizational-chart';


const StyledTreeExample = () => (
    <Tree
      lineWidth={'2px'}
      lineColor={'green'}
      lineBorderRadius={'10px'}
      label={"Root"}
    >
      <TreeNode label={"Child 1"}>
        <TreeNode label={"Grand Child"} />
      </TreeNode>
      <TreeNode label={"Child 2"}>
        <TreeNode label={"Grand Child"}>
          <TreeNode label={"Great Grand Child 1"} />
          <TreeNode label={"Great Grand Child 2"} />
        </TreeNode>
      </TreeNode>
      <TreeNode label={"Child 3"}>
        <TreeNode label={"Grand Child 1"} />
        <TreeNode label={"Grand Child 2"} />
      </TreeNode>
    </Tree>
  );

StyledTreeExample()
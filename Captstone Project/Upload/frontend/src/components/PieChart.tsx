import { useState, useMemo } from "react";
import { Pie } from "@visx/shape";
import { Group } from "@visx/group";
import { Text } from "@visx/text";
import { PieProp } from "../types.ts";
import { GetPieChartData } from "../services/homePageKPI.ts";

function PieChart(props: { width: number }) {
    const data = GetPieChartData()
    const { width } = props;
    const [active, setActive] = useState<PieProp>(null);
    const half = width / 2;

    const total = useMemo(
        () =>
            data.reduce((accumulator, expense) => accumulator + expense.amount, 0),
        []);

    return (
        <svg width={width} height={width}>
            <Group top={half} left={half}>
                <Pie
                    data={data}
                    pieValue={(data) => data.amount}
                    outerRadius={half}
                    innerRadius={({ data }) => {
                        const size = active && data.type === active.type ? 72 : 54;
                        return half - size;
                    }}
                    cornerRadius={3}
                    padAngle={0.005}
                >
                    {(pie) => {
                        return pie.arcs.map((arc) => {
                            const [centroidX, centroidY] = pie.path.centroid(arc);
                            return arc.data.count && (
                                <g
                                    key={arc.data.idx}
                                    onMouseEnter={() => setActive(arc.data)}
                                    onMouseLeave={() => setActive(null)}
                                >
                                    <path d={pie.path(arc)} fill={arc.data.color}></path>
                                </g>
                            );
                        });
                    }}
                </Pie>

                {active ? (
                    <>
                        <Text textAnchor="middle" fill="#111" fontSize={20} dy={0}>
                            {`₹${Math.floor(active.amount)}`}
                        </Text>

                        <Text
                            textAnchor="middle"
                            fontWeight={20}
                            fontSize={20}
                            dy={40}
                        >
                            {`${active.type}`}
                        </Text>
                    </>
                ) : (
                    <>
                        <Text textAnchor="middle" fill="#111" fontSize={20} dy={0}>
                            {`₹${total}`}
                        </Text>

                        <Text textAnchor="middle" fill="#888" fontSize={20} dy={40}>
                            {`${data.length} Assets`}
                        </Text>
                    </>
                )}
            </Group>
        </svg>
    );
}

export { PieChart };
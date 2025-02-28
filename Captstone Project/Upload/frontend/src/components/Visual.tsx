import { curveCardinal } from "@visx/curve";
import CustomChartBackground from "./CustomChartBackground.tsx";
import Graph from "./Graph.tsx";
import { CityTemperature } from "@visx/mock-data/lib/mocks/cityTemperature";
import { AnimatedBarSeries, AnimatedBarStack } from '@visx/xychart';
import { BarDataProps, Expense } from "../types.ts";
import { useUser } from "./UserState.tsx";

export type XYChartProps = {
    width: number;
    height: number;
    data: BarDataProps[]
}

export default function Visual({ width, height, data }: XYChartProps) {
    return (
        <Graph>
            {({
                accessors,
                animationTrajectory,
                numTicks,
                config,
                annotationDataKey,
                annotationDataIndex,
                annotationLabelPosition,
                setAnnotationDataKey,
                setAnnotationDataIndex,
                setAnnotationLabelPosition,
                snapTooltipToDatumX,
                snapTooltipToDatumY,
                theme,
                xOrientation,
                yOrientation,
                renderHorizontally,
                renderTooltipGlyph,
                renderAreaSeries,
                renderBarSeries,
                Annotation,
                AreaSeries,
                AreaStack,
                Axis,
                BarGroup,
                BarSeries,
                BarStack,
                GlyphSeries,
                Grid,
                LineSeries,
                AnnotationCircleSubject,
                AnnotationConnector,
                AnnotationLabel,
                AnnotationLineSubject,
                Tooltip,
                XYChart,
            }) => (
                <XYChart
                    theme={theme}
                    xScale={config.x}
                    yScale={config.y}
                    height={Math.min(400, height)}
                    onPointerUp={(d) => {
                        setAnnotationDataKey(d.key as 'Flight' | 'Relocation' | 'Mobile Bill' | 'Outing' | 'Wifi' | 'Food')
                        setAnnotationDataIndex(d.index)
                    }}
                >
                    <CustomChartBackground />
                    <Grid rows={true} cols="true" />
                    <AnimatedBarStack>
                        <AnimatedBarSeries
                            dataKey="Flight"
                            data={data}
                            xAccessor={accessors.x['Flight']}
                            yAccessor={accessors.y['Flight']}
                        />
                        <AnimatedBarSeries
                            dataKey="Relocation"
                            data={data}
                            xAccessor={accessors.x['Relocation']}
                            yAccessor={accessors.y['Relocation']}
                        />
                        <AnimatedBarSeries
                            dataKey="Mobile Bill"
                            data={data}
                            xAccessor={accessors.x['Mobile Bill']}
                            yAccessor={accessors.y['Mobile Bill']}
                        />
                        <AnimatedBarSeries
                            dataKey="Outing"
                            data={data}
                            xAccessor={accessors.x['Outing']}
                            yAccessor={accessors.y['Outing']}
                        />
                        <AnimatedBarSeries
                            dataKey="Wifi"
                            data={data}
                            xAccessor={accessors.x['Wifi']}
                            yAccessor={accessors.y['Wifi']}
                        />
                        <AnimatedBarSeries
                            dataKey="Food"
                            data={data}
                            xAccessor={accessors.x['Food']}
                            yAccessor={accessors.y['Food']}
                        />
                    </AnimatedBarStack>
                    <Axis
                        key={`time-axis-${animationTrajectory}-${renderHorizontally}`}
                        orientation={renderHorizontally ? yOrientation : xOrientation}
                        numTicks={numTicks}
                        label="Time Period"
                    />
                    <Axis
                        key={`temp-axis-${animationTrajectory}-${renderHorizontally}`}
                        label={
                            "Amount"
                        }
                        orientation={renderHorizontally ? xOrientation : yOrientation}
                        numTicks={numTicks}
                    />
                    {annotationDataKey && data[annotationDataIndex] && (
                        <Annotation
                            dataKey={annotationDataKey}
                            datum={data[annotationDataIndex]}
                            dx={annotationLabelPosition.dx}
                            dy={annotationLabelPosition.dy}
                            canEditSubject={false}
                            onDragEnd={({ dx, dy }) => setAnnotationLabelPosition({ dx, dy })}
                        >
                            <AnnotationConnector />
                            <AnnotationCircleSubject />
                            <AnnotationLabel
                                title={annotationDataKey}
                                subtitle={`${data[annotationDataIndex].date_of_expense}, ${data[annotationDataIndex][annotationDataKey]} ₹`}
                                width={135}
                                backgroundProps={{
                                    stroke: theme.gridStyles.stroke,
                                    strokeOpacity: 0.5,
                                    fillOpacity: 0.8,
                                }}
                            />
                        </Annotation>
                    )}
                    <Tooltip<BarDataProps>
                        showHorizontalCrosshair={true}
                        showVerticalCrosshair={true}
                        snapTooltipToDatumX={snapTooltipToDatumX}
                        snapTooltipToDatumY={snapTooltipToDatumY}
                        renderGlyph={renderTooltipGlyph}
                        renderTooltip={({ tooltipData, colorScale }) => (
                            <>
                                {/** date */}
                                {(tooltipData?.nearestDatum?.datum &&
                                    accessors.date(tooltipData?.nearestDatum?.datum)) ||
                                    'No date'}
                                <br />
                                <br />
                                {/** temperatures */}
                                {(
                                    (
                                        Object.keys(tooltipData?.datumByKey ?? {})
                                    ).filter((city) => city) as string[]
                                ).map((city) => {
                                    const expense =
                                        tooltipData?.nearestDatum?.datum &&
                                        accessors[renderHorizontally ? 'x' : 'y'][city](
                                            tooltipData?.nearestDatum?.datum,
                                        );

                                    return (
                                        <div key={city}>
                                            <em
                                                style={{
                                                    color: colorScale?.(city),
                                                    textDecoration:
                                                        tooltipData?.nearestDatum?.key === city ? 'underline' : undefined,
                                                }}
                                            >
                                                {city}
                                            </em>{' '}
                                            {expense == null || Number.isNaN(expense)
                                                ? '–'
                                                : `${expense} ₹`}
                                        </div>
                                    );
                                })}
                            </>
                        )}
                    />
                </XYChart>
            )
            }
        </Graph>
    );
}
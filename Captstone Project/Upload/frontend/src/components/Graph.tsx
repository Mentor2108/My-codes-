import { lightTheme, XYChartTheme } from "@visx/xychart";
import { useCallback, useMemo, useState } from "react";
import { RenderTooltipGlyphProps } from "@visx/xychart/lib/components/Tooltip";
import { GlyphCircle, GlyphCross } from "@visx/glyph";
import getAnimatedOrUnanimatedComponents from "../config/getAnimatedOrUnanimatedComponents.ts";
import { AnimationTrajectory } from "@visx/react-spring";
import { BarDataProps } from "../types.ts";

const dateScaleConfig = { type: 'band', paddingInner: 0.3 } as const;
const temperatureScaleConfig = { type: 'linear' } as const;
const defaultAnnotationDataIndex = 13

type SimpleScaleConfig = { 'type': 'band' | 'linear'; padding?: number }




const getDate = (d:BarDataProps) => d.date_of_expense
const getFlightExpense = (d:BarDataProps) => d.flight
const getMobileBillExpense = (d:BarDataProps) => d.mobile_bill
const getOutingExpense = (d:BarDataProps) => d.outing
const getRelocationExpense = (d:BarDataProps) => d.relocation
const getWifiExpense = (d:BarDataProps) => d.wifi
const getFoodExpense = (d:BarDataProps) => d.food


type Accessor = (d: BarDataProps) => number | Date;

interface Accessors {
    'Flight': Accessor;
    'Mobile Bill': Accessor;
    'Outing': Accessor;
    'Relocation': Accessor;
    'Wifi': Accessor;
    'Food': Accessor;
}

type DataKey = keyof Accessors;

type ProvidedProps = {
    accessors: {
        x: Accessors,
        y: Accessors,
        date: Accessor;
    }
    animationTrajectory?: AnimationTrajectory
    numTicks: number;
    config: {
        x: SimpleScaleConfig;
        y: SimpleScaleConfig;
    }
    annotationDataKey: DataKey | null;
    annotationDataIndex: number;
    annotationLabelPosition: { dx: number, dy: number };
    setAnnotationDataKey: (key: DataKey | null) => void;
    setAnnotationDataIndex: (index: number) => void;
    setAnnotationLabelPosition: (position: { dx: number, dy: number }) => void;
    snapTooltipToDatumX: boolean;
    snapTooltipToDatumY: boolean;
    theme: XYChartTheme
    xOrientation: 'top' | 'bottom';
    yOrientation: 'left' | 'right';
    renderHorizontally: boolean
    renderTooltipGlyph: React.FC<RenderTooltipGlyphProps<BarDataProps>>
    renderAreaSeries: boolean;
    renderBarSeries: boolean;
} & ReturnType<typeof getAnimatedOrUnanimatedComponents>

type ControlProps = {
    children: (props: ProvidedProps) => React.ReactNode
}

export default function Graph({ children }: ControlProps) {
    const [theme, setTheme] = useState<XYChartTheme>(lightTheme);
    const [xOrientation, setXOrientation] = useState<'top' | 'bottom'>('bottom');
    const [yOrientation, setYOrientation] = useState<'left' | 'right'>('right');
    const [snapTooltipX, setSnapTooltipX] = useState(false)
    const [snapTooltipY, setSnapTooltipY] = useState(false)
    const [annotationLabelPosition, setAnnotationLabelPosition] = useState({ dx: -40, dy: 20 });
    const glyphOutline = theme.gridStyles.stroke
    const [tooltipGlyphComponent, setTooltipGlyphComponent] = useState<'cross' | 'circle'>('circle');
    const [renderHorizontally, setRenderHorizontally] = useState(false)
    const [animationTrajectory, setAnimationTrajectory] = useState<AnimationTrajectory | undefined>('min')
    const [annotationDataIndex, setAnnotationDataIndex] = useState(defaultAnnotationDataIndex)
    const [annotationDataKey, setAnnotationDataKey] =
        useState<ProvidedProps['annotationDataKey']>(null);
    const [negativeValues, setNegativeValues] = useState(false);

    
    const renderTooltipGlyph = useCallback(
        ({
            x,
            y,
            size,
            color,
            onPointerMove,
            onPointerOut,
            onPointerUp,
            isNearestDatum
        }: RenderTooltipGlyphProps<BarDataProps>) => {
            const handlers = { onPointerMove, onPointerOut, onPointerUp };
            if (tooltipGlyphComponent === 'circle') {
                return <GlyphCircle
                    left={x}
                    top={y}
                    stroke={glyphOutline}
                    fill={color}
                    size={size * 10}
                    {...handlers}
                />
            }
            return <GlyphCross
                left={x}
                top={y}
                stroke={glyphOutline}
                fill={color}
                size={size * 10}
                {...handlers}
            />
        },
        [tooltipGlyphComponent, glyphOutline]);

    const config = useMemo(
        () => ({
            x: renderHorizontally ? temperatureScaleConfig : dateScaleConfig,
            y: renderHorizontally ? dateScaleConfig : temperatureScaleConfig
        }),
        [renderHorizontally]
    );
    const accessors = useMemo(
        () => ({
            x: {
                'Flight': renderHorizontally? getFlightExpense: getDate,
                'Mobile Bill': renderHorizontally? getMobileBillExpense: getDate,
                'Outing': renderHorizontally? getOutingExpense: getDate,
                'Relocation': renderHorizontally? getRelocationExpense: getDate,
                'Wifi': renderHorizontally? getWifiExpense: getDate,
                'Food': renderHorizontally? getFoodExpense: getDate
            },
            y: {
                'Flight': renderHorizontally? getDate: getFlightExpense,
                'Mobile Bill': renderHorizontally? getDate: getMobileBillExpense,
                'Outing': renderHorizontally? getDate: getOutingExpense,
                'Relocation': renderHorizontally? getDate: getRelocationExpense,
                'Wifi': renderHorizontally? getDate: getWifiExpense,
                'Food': renderHorizontally? getDate: getFoodExpense
            },
            date: getDate,
        }),
        [renderHorizontally, negativeValues],
    );

    return (
        <>
            {children({
                accessors,
                animationTrajectory,
                numTicks: 4,
                config,
                annotationDataKey: annotationDataKey,
                annotationDataIndex: annotationDataIndex,
                annotationLabelPosition,
                setAnnotationDataKey,
                setAnnotationDataIndex,
                setAnnotationLabelPosition,
                snapTooltipToDatumX: false,
                snapTooltipToDatumY: false,
                theme,
                xOrientation,
                yOrientation,
                renderHorizontally,
                renderTooltipGlyph,
                renderAreaSeries: false,
                renderBarSeries: false,
                ...getAnimatedOrUnanimatedComponents()
            })}
        </>
    );
}
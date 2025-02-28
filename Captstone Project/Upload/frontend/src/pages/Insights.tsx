import { ParentSize } from "@visx/responsive";
import Visual from "../components/Visual.tsx";
import { SdfDatePickerV2, SdfSegmentedControl, SdfSuperTitle } from "@waypoint/react-components";
import { useState } from "react";
import { PieChart } from "../components/PieChart.tsx";
import { GetExpensesBetweenDates } from "../services/homePageKPI.ts";
import { useUser } from "../components/UserState.tsx";
import InlineError from "../components/InlineError.tsx";

type Item = { label: string, value: string };

const segmentedControlItems: Item[] = [
    { label: "Bar", value: "bar" },
    { label: "Pie", value: "pie" }
];

interface ErrorState {
    error: string;
    value: boolean;
}

export default function Analytics() {
    const currDate = new Date()
    const lastYearDate = new Date(currDate.getFullYear() - 1, currDate.getMonth(), currDate.getDate())
    const [fromDate, setFromDate] = useState<Date>(lastYearDate)
    const [toDate, setToDate] = useState<Date>(currDate)
    const [index, setIndex] = useState<number>(0)
    const [errorMessage, setErrorMessage] = useState<ErrorState>({ error: "", value: false });

    function handleFromDateChange(evt: CustomEvent<string>) {
        if (new Date(evt.detail) > toDate) {
            setErrorMessage({ error: "Set valid Range!", value: true })
        } else {
            setFromDate(new Date(evt.detail))
            setErrorMessage({ error: "", value: false })
        }
    }
    function handleToDateChange(evt: CustomEvent<string>) {
        if (!fromDate) {
            setErrorMessage({ error: "Set from date first!", value: true })
        }
        else if (fromDate > new Date(evt.detail)) {
            setErrorMessage({ error: "Set valid Range!", value: true })
        } else {
            setToDate(new Date(evt.detail))
            setErrorMessage({ error: "", value: false })
        }
    }
    function handleIndexChange(evt: CustomEvent<number>) {
        setIndex(evt.detail)
    }
    const { userDetails } = useUser();
    return (
        <div>
            <SdfSuperTitle><h1>Insights</h1></SdfSuperTitle>
            <div className="flex pl-5"><h2>A glance at your expenses...</h2></div>
            <div className="flex p-2 grid lg:grid-cols-2 md:grid-cols-1 md:w-96">
                <div className="flex items-end mr-4">
                    <SdfSegmentedControl selectedIndex={index} onSdfChange={handleIndexChange} items={segmentedControlItems} />
                </div>
                <div>
                    <div className="flex grid lg:grid-cols-2 md:grid-cols-1">
                        <SdfDatePickerV2 id="date1" className="p-1" onSdfChange={handleFromDateChange} label="From" value={fromDate.toISOString()} />
                        <SdfDatePickerV2 id="date2" className="p-1" onSdfChange={handleToDateChange} label="To" value={toDate.toISOString()} />
                    </div>
                    {errorMessage.value && <InlineError message={errorMessage.error} />}
                </div>
            </div>
            <div style={{ width: '100%', height: '500px', marginTop: '50px' }}>
                {index == 0 && !errorMessage.value && <ParentSize>{({ width, height }) => <Visual width={width} height={height} data={GetExpensesBetweenDates(fromDate, toDate, userDetails.currentUser.expense)} />}</ParentSize>}
                {
                    index == 1 &&
                    <div className="flex justify-center items-center">
                        <PieChart width={400} />
                    </div>
                }
            </div>
        </div>
    );
}
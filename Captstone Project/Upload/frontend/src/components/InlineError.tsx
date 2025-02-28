import { SdfAlertInline } from "@waypoint/react-components";

function InlineError({message}){
    return (
        <SdfAlertInline size="sm" status="error" emphasis="primary" className="p-1">
            <span>{message}</span>
        </SdfAlertInline>
    );
}

export default InlineError;
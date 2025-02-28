import { SdfAlertInline } from "@waypoint/react-components";

export function LogoutError({message}){
    return (
        <SdfAlertInline size="sm" status="error" emphasis="primary" className="p-1">
            <span>{message}</span>
        </SdfAlertInline>
    );
}
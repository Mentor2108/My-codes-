import { SdfSpotIllustration } from "@waypoint/react-components";
export default function Illustration({transformation="",name}) {
    return (
        <div className="relative mx-auto flex-shrink flex-grow">
            <div className={`${transformation}`}>
                <SdfSpotIllustration illustration-name={name} size="lg" />
            </div>
        </div>
    );
}
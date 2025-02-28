import { SdfAlertBanner } from "@waypoint/react-components";

export default function ErrorBanner(props: { message: string, setMessage: React.Dispatch<React.SetStateAction<string>> }) {
    const { message, setMessage } = props

    return (
        <SdfAlertBanner
            status="error"
            use-animation={true}
            icon-title="bad-credentials-icon"
            icon="alert-error"
            closeable=""
            auto-close-after={5000}
            auto-close={true}
            onSdfAfterClose={() => {
                setMessage(null);
            }}
            close-icon-title="close-bad-credentials-banner"
            id="bad-credentials"
        >
            <span>{message}</span>
        </SdfAlertBanner>)
}
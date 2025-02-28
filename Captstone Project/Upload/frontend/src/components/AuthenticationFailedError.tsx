import { SdfAlertToast } from '@waypoint/react-components';
import { Navigate, useNavigate } from 'react-router-dom';

export default function AuthenticationFailedError(props:{route:string}) {
    const {route} = props;
    const navigate = useNavigate();

    

    function navigateToRoute(route: string) {
        navigate(route, {replace: true});
    }

    return (
        <div>
            <SdfAlertToast
                message="Your session has expired. Please sign in again to continue."
                id="authentication-error"
                action-label="Sign in"
                auto-close={true}
                auto-close-after={10000}
                button-title="authentication-error-button"
                close-icon-title="authentication-error-close"
                closeable=""
                icon-title="authentication-error-icon"
                status="error"
                use-animation={true}
                onSdfAction={() => navigateToRoute(route)}
                onSdfAfterClose={() => navigateToRoute(route)}
          ></SdfAlertToast>
        </div>
    );
};
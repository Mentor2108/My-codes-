import { useReducer, useState } from 'react';
import { SdfAlertBanner, SdfButton, SdfFocusPane, } from '@waypoint/react-components';
import Profile from '../Profile/Profile.tsx';
import { profileReducer, useProfileData } from '../Profile/reducersWithInitialStates.ts';
import axios, { AxiosError, AxiosResponse } from "axios";
import { EPerson, Gender, IAddress, IPerson } from '../../types.ts';
import { validateProfileInput, validateRegisterAddressInput } from '../ValidateDetails.tsx';
import ErrorBanner from '../ErrorBanner.tsx';

const todaysDate = new Date().getDate().toString();
const initialAddress: IAddress = {
    address_type: "Current",
    city: "",
    country: "",
    line_one: "",
    line_two: "",
    postal_code: "",
    state: "",
    street: ""
};

const registerInitialState: IPerson = {
    firstname: "",
    lastname: "",
    email: "",
    password: "",
    manager: "",
    currentAddress: initialAddress,
    permanentAddress: initialAddress,
    gender: Gender.FEMALE,
    dateofbirth: ''
}

const registerPersonError: EPerson = {
    firstname: null,
    lastname: null,
    email: null,
    password: null,
    gender: null,
    dateofbirth: null,
    manager: null,
    currentAddress: null,
    permanentAddress: null
}

function Register() {
    const [visibility, setVisibility] = useState(false);
    const [profileResponse, setProfileResponse] = useState<string | null>(null);
    const [successProfileResponse, setSuccessProfileResponse] = useState<string | null>(null);

    const { profileInitialState } = useProfileData()

    const handleAccept = async (evt) => {
        const email = state.input.email;
        const first_name = state.input.firstname;
        const last_name = state.input.lastname;
        const gender = state.input.gender.toString();
        const password = state.input.password;
        const date_of_birth = state.input.dateofbirth;
        const manager_id = "12345";
        const current = state.input.currentAddress;
        const permanent = state.input.permanentAddress;
        current.address_type = "Current";
        permanent.address_type = "Permanent";
        const final =
            (permanent.country === null || permanent.country === '' || permanent.country === undefined || permanent === initialAddress) ?
                { first_name, last_name, email, gender, date_of_birth, manager_id, password, "address": [{ ...current }] }
                : { first_name, last_name, email, gender, date_of_birth, manager_id, password, "address": [{ ...current }, { ...permanent }] };
        let hasError = false;

        (Object.keys(state.input) as (keyof IPerson)[]).forEach((field) => {
            const error = validateRegisterAddressInput(field, state.input[field]) || validateProfileInput(field, state.input[field]);
            if (error) {
                hasError = true;
                dispatch({ type: 'ERROR_PERSONAL_DETAILS', field: field, value: error })
            }
        })

        if (!hasError) {
            await axios.post('http://localhost:6769/auth/signup',
                final, {
                withCredentials: true
            }
            ).then((response: AxiosResponse) => {
                if (response.status && response.status === 200) {
                    if (response.data.error === "could not connect to server") {
                        setProfileResponse("User already exists");
                        setVisibility(true);
                    }
                    else {
                        setSuccessProfileResponse("Personal Details  Updated Successfull");
                        setVisibility(false);
                    }
                }
                else {
                    setProfileResponse("Something went wrong");
                    setVisibility(true);
                }
            }).catch((error: AxiosError) => {
                if (error.status && error.status === 403) {
                    setProfileResponse("User already exists. Please Loging using Credentials");
                } else {
                    setProfileResponse("Something went wrong. Please try again.");
                }
            });
        }
    };

    const handleButtonClick = () => {
        setVisibility(true)
    }

    const handleDismiss = (evt) => {
        dispatch({
            type: 'RESET',
            payload: { profileInitialState }
        })
        evt.currentTarget.close();
        setVisibility(false);
    };
    const [state, dispatch] = useReducer(profileReducer, { input: registerInitialState, error: registerPersonError });

    return (
        <div>
            <section className="flex items-center justify-center h-full">
                <SdfButton id="open-button" onClick={handleButtonClick} emphasis="tertiary">Not Registered yet?</SdfButton>
                <SdfFocusPane
                    closeable={true}
                    spacing="loose"
                    heading="Register"
                    pane-type="anchored"
                    id="demo-component"
                    visible={visibility}
                    dismissOnClickOutside={true}
                    acceptAction="standard"
                    disableDismissButton={false}
                    enableEnhancedAccessibility={true}
                    onSdfAccept={handleAccept}
                    size="lg"
                    onSdfDismiss={handleDismiss}
                >
                    <div>
                        {
                            successProfileResponse && <SdfAlertBanner
                                status="success"
                                use-animation={true}
                                icon-title="bad-credentials-icon"
                                icon="alert-error"
                                closeable=""
                                auto-close-after={5000}
                                auto-close={true}
                                close-icon-title="close-bad-credentials-banner"
                                id="bad-credentials"
                                onSdfAfterClose={() => {
                                    setSuccessProfileResponse(null);
                                }}
                            >
                                <span>{successProfileResponse}</span>
                            </SdfAlertBanner>
                        }
                    </div>
                    <div>
                        {
                            profileResponse && <ErrorBanner message={profileResponse} setMessage={setProfileResponse} />
                        }
                    </div>
                    <Profile state={state} dispatch={dispatch} compEditable={false} />
                </SdfFocusPane>
            </section>
        </div>
    );
}

export { Register };
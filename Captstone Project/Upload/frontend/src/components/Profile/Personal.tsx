import {
    SdfAlertBanner,
    SdfButton,
    SdfDatePicker,
    SdfDatePickerV2,
    SdfIcon,
    SdfIconButton,
    SdfInput,
    SdfSelectItem,
    SdfSelectSimple,
} from '@waypoint/react-components';
import { EPerson, IPerson, PersonAction } from '../../types.ts';
import { useState } from 'react';
import InlineError from '../InlineError.tsx';
import { validateEditProfileInput, validateProfileInput } from '../ValidateDetails.tsx';
import axios, { AxiosError, AxiosResponse } from "axios";
import { initialAddress, useProfileData } from './reducersWithInitialStates.ts';
import { useUser } from '../UserState.tsx';
import ErrorBanner from '../ErrorBanner.tsx';

const todaysDate = new Date().getDate().toString()

function Person(props: {
    state: { input: IPerson, error: EPerson },
    dispatch: React.Dispatch<PersonAction>,
    editable: boolean
}) {

    const { state, dispatch, editable } = props;
    const handleChange = (evt) => {
        const { name, value } = evt.target;
        const field = name as keyof IPerson;
        switch (field) {
            case 'email':
            case 'manager':
            case 'firstname':
            case 'lastname':
            case 'dateofbirth':
            case 'password':
                dispatch({ type: 'SET_PERSONAL_DETAILS', field: field, value: value });
                const error = validateProfileInput(field, value)
                dispatch({ type: 'ERROR_PERSONAL_DETAILS', field: field, value: error })
                break;
            case 'gender':
                dispatch({ type: 'SET_PERSONAL_DETAILS', field: field, value: value.value });
                break;
        }
    }
    const [edit, setEdit] = useState(false)

    const [personalResponse, setPersonalResponse] = useState<string | null>(null);
    const [successPersonalResponse, setSuccessPersonalResponse] = useState<string | null>(null);


    const { userDetails } = useUser();
    const containerStyle = {
        display: 'grid',
        gap: '1rem',
    };

    const rowStyle = {
        display: 'grid',
        gridTemplateColumns: 'repeat(auto-fit, minmax(250px, 1fr))',
        gap: '1rem',
    };

    const colStyle = {
        display: 'flex',
        flexDirection: 'column',
    };




    const [data, setData] = useState({});
    const { profileInitialState } = useProfileData();

    // dispatch({
    //     type: 'RESET',
    //     payload: { profileInitialState }
    // })


    async function handleUpdate() {
        const current = state.input.currentAddress;
        const permanent = state.input.permanentAddress;
        const email = state.input.email;
        const first_name = state.input.firstname;
        const last_name = state.input.lastname;
        const gender = state.input.gender.toString();
        const password = state.input.password;
        const date_of_birth = state.input.dateofbirth;
        const final =
            (permanent.country === null || permanent.country === '' || permanent.country === undefined || permanent === initialAddress) ?
                { first_name, last_name, email, gender, date_of_birth, "address": [{ ...current }] }
                : { first_name, last_name, email, gender, date_of_birth, "address": [{ ...current }, { ...permanent }] };

        let hasError = false;

        (Object.keys(state.input) as (keyof IPerson)[]).forEach((field) => {
            const error = validateEditProfileInput(field, state.input[field]);
            if (error) {
                hasError = true;
                dispatch({ type: 'ERROR_PERSONAL_DETAILS', field: field, value: error })
            }
        })

        if (!hasError) {
            if (userDetails.currentUser.id) {
                await axios.put(`http://localhost:6769/api/employee/update/id/${userDetails.currentUser.id}`,
                    final, {
                    withCredentials: true
                }
                ).then((response: AxiosResponse) => {
                    if (response.status && response.status === 200) {
                        setSuccessPersonalResponse("Personal Details  Updated Successfull");
                        if (response.data.error === "could not connect to server") {
                            setPersonalResponse("Email already exists.");
                            setEdit(true);
                        }
                        else {
                            setEdit(false)
                        }

                    }
                    else {
                        setPersonalResponse("Something went wrong. Please try again.");

                    }
                }).catch((error: AxiosError) => {
                    if (error.status && error.status === 403) {
                        setPersonalResponse("Invalid Login Credentials. Please enter correct details.");
                    } else {
                        setPersonalResponse("Unable to update");
                    }
                });

            }
        }
    }

    return (
        <div style={containerStyle}>
            <div>
                <div>
                    <div>
                        {
                            personalResponse && <ErrorBanner message={personalResponse} setMessage={setPersonalResponse} />
                        }
                    </div>
                    <div>
                        {
                            successPersonalResponse && <SdfAlertBanner
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
                                    setSuccessPersonalResponse(null);
                                }}
                            >
                                <span>{successPersonalResponse}</span>
                            </SdfAlertBanner>
                        }
                    </div>
                </div>
            </div>
            <div style={rowStyle}>
                <div className='flex justify-between'>
                    <h2 className='text-heading-05'>
                        Personal Details
                    </h2>
                    {editable && <div className='flex items-center'>
                        <SdfIconButton onClick={() => {
                            dispatch({
                                type: 'RESET',
                                payload: { profileInitialState }
                            })
                            setEdit(true)
                        }

                        }>


                            <SdfIcon icon="action-edit" />
                        </SdfIconButton>
                    </div>}
                </div>
            </div>
            <div style={rowStyle}>
{/* 
                <div style={colStyle}>
                    <SdfInput
                        name="email"
                        label="Email"
                        id="associate-id"
                        inputType="email"
                        type="email"
                        required-state="required"
                        value={state.input.email}
                        placeholder={profileInitialState.email}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                    >
                    </SdfInput>
                    {state.error.email && <InlineError message={state.error.email} />}
                </div> */}

                {!editable &&
                    <div style={colStyle}>
                        <SdfInput
                            name="email"
                            label="Email"
                            id="associate-id"
                            inputType="email"
                            type="email"
                            required-state="required"
                            value={state.input.email}
                            placeholder={profileInitialState.email}
                            onSdfChange={handleChange}
                            disabled={!edit && editable}
                        >
                        </SdfInput>
                        {state.error.email && <InlineError message={state.error.email} />}
                    </div>
                }
                {editable && <div style={colStyle}>
                    <SdfInput
                        name="manager"
                        label="Reporting To"
                        id="reporting_to"
                        inputType="text"
                        value={state.input.manager}
                        placeholder={profileInitialState.firstname}
                        onSdfChange={handleChange}
                        disabled={editable}
                    />
                </div>
                }
                <div style={colStyle}>
                    <SdfInput
                        name="firstname"
                        label="First Name"
                        id="first-name"
                        inputType="text"
                        required-state="required"
                        value={state.input.firstname}
                        placeholder={profileInitialState.firstname}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                    >
                    </SdfInput>
                    {state.error.firstname && <InlineError message={state.error.firstname} />}
                </div>

                <div style={colStyle}>
                    <SdfInput
                        name="lastname"
                        label="Last Name"
                        id="last-name"
                        inputType="text"
                        value={state.input.lastname}
                        placeholder={profileInitialState.lastname}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                    >
                    </SdfInput>
                </div>
            </div>

            <div style={rowStyle}>
                <div style={colStyle}>
                    <SdfSelectSimple
                        name="gender"
                        id="gender"
                        label="Gender"
                        value={{ label: state.input.gender, value: state.input.gender }}
                        placeholder={`${profileInitialState.gender}`}
                        disabled={!edit && editable}
                        onSdfChange={handleChange}
                    >
                        <SdfSelectItem value="MALE">MALE</SdfSelectItem>
                        <SdfSelectItem value="FEMALE">FEMALE</SdfSelectItem>
                        <SdfSelectItem value="OTHER">OTHER</SdfSelectItem>
                    </SdfSelectSimple>
                </div>
                <div style={colStyle}>
                    <SdfDatePickerV2
                        name="dateofbirth"
                        label="Date of Birth"
                        id="demo-component"
                        required-state="required"
                        value={state.input.dateofbirth}
                        placeholder={`${profileInitialState.dateofbirth}`}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                    >
                    </SdfDatePickerV2>
                    {state.error.dateofbirth && <InlineError message={state.error.dateofbirth} />}
                </div>
                {!editable && <div style={colStyle}>
                    <SdfInput
                        name="password"
                        label="Password"
                        id="email"
                        type="password"
                        required-state="required"
                        value={state.input.password}
                        placeholder={state.input.password}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                    >
                    </SdfInput>
                    {state.error.password && <InlineError message={state.error.password} />}
                </div>
                }

                {editable && <div style={colStyle}>
                    <SdfInput
                        name="password"
                        label="Password"
                        id="email"
                        type="password"
                        value={state.input.password}
                        placeholder={state.input.password}
                        onSdfChange={handleChange}
                        disabled
                        readonly={!edit && editable}
                    >
                    </SdfInput>
                </div>
                }
            </div>
            {edit && <div className='flex space-x-4'>
                <SdfButton onClick={() => {
                    handleUpdate()
                }}>Update</SdfButton>
                <SdfButton onClick={() => {
                    dispatch({
                        type: 'RESET',
                        payload: { profileInitialState }
                    })
                    setEdit(false)
                }} action="destructive">Cancel</SdfButton>
            </div>}
        </div>
    );
}

export { Person };


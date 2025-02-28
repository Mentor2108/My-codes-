import { SdfAlertBanner, SdfButton, SdfInput, SdfSelectItem, SdfSelectSimple, SdfTextarea } from "@waypoint/react-components";
import InlineError from "../InlineError.tsx";
import { useState } from "react";
import { AddressType, EPerson, IAddress, IPerson, PersonAction } from "../../types.ts";
import { City, Country, ICity, ICountry, IState, State } from "country-state-city";
import { validateRegisterAddressInput } from "../ValidateDetails.tsx";
import axios, { AxiosError, AxiosResponse } from "axios";
import { initialAddress, useProfileData } from "./reducersWithInitialStates.ts";
import { useUser } from "../UserState.tsx";
import ErrorBanner from "../ErrorBanner.tsx";

const GetCodeByCountry = (countryName: string) => {
    return Country.getAllCountries().find((c: ICountry) => c.name === countryName).isoCode
}

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


export default function AddressComponent(props: {
    addressType: AddressType,
    state: { input: IPerson, error: EPerson },
    dispatch: React.Dispatch<PersonAction>,
    editable: boolean,
    edit: boolean,
    setEdit
}) {
    const { addressType, state, dispatch, editable, edit, setEdit } = props;
    const [countries, setCountries] = useState(Country.getAllCountries());
    const [states, setStates] = useState<IState[]>([]);
    const [cities, setCities] = useState<ICity[]>([]);
    const [addressResponse, setAddressResponse] = useState<string | null>(null);
    const [successAddressResponse, setSuccessAddressResponse] = useState<string | null>(null);


    const dispatchType = (addressType === AddressType.CURRENT_ADDRESS) ? 'SET_CURRENT_ADDRESS' : 'SET_PERMANENT_ADDRESS';

    const address = (addressType === AddressType.CURRENT_ADDRESS) ? state.input.currentAddress : state.input.permanentAddress

    const { profileInitialState } = useProfileData();
    const { userDetails } = useUser();

    const handleChange = (evt) => {
        const { name, value } = evt.target;
        const field = name as keyof IAddress;
        switch (field) {
            case 'country': {
                setStates(State.getStatesOfCountry(value.value))
                dispatch({ type: dispatchType, field: field, value: value.label })
            } break;
            case 'state': {
                setCities(City.getCitiesOfState(GetCodeByCountry(address.country), value.value))
                dispatch({ type: dispatchType, field: field, value: value.label })
            } break;
            case 'city': {
                dispatch({ type: dispatchType, field: field, value: value.label })
            } break;
            case 'postal_code':
            case 'line_one':
            case 'line_two':
            case 'street':
                dispatch({ type: dispatchType, field: field, value: value })
                break
        }
    }


    async function handleUpdate() {
        const current = state.input.currentAddress;
        const permanent = state.input.permanentAddress;
        const email = state.input.email;
        const first_name = state.input.firstname;
        const last_name = state.input.lastname;
        const gender = state.input.gender.toString();
        const password = state.input.password;
        const date_of_birth = state.input.dateofbirth;
        permanent.address_type = "Permanent";

        const final =
            (permanent.country === null || permanent.country === '' || permanent.country === undefined || permanent === initialAddress) ?
                { first_name, last_name, email, gender, date_of_birth, "address": [{ ...current }] }
                : { first_name, last_name, email, gender, date_of_birth, "address": [{ ...current }, { ...permanent }] };

        let hasError = false;

        (Object.keys(state.input) as (keyof IAddress)[]).forEach((field) => {
            if (addressType === AddressType.CURRENT_ADDRESS) {
                const error = validateRegisterAddressInput(field, state.input[field]);

                if (error) {
                    hasError = true;
                    dispatch({ type: 'ERROR_PERSONAL_DETAILS', field: field, value: error })
                }
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
                        setSuccessAddressResponse("Address Details Updated Successfully");
                    }
                    else {
                        setAddressResponse("Something went wrong. Please try again.");
                    }
                }).catch((error: AxiosError) => {
                    if (error.status && error.status === 403) {
                        setAddressResponse("Invalid Login Credentials. Please enter correct details.");
                    }
                    if (error.status && error.status === 401) {
                        setAddressResponse("Unable to Update Details");
                    }
                    else {
                        setAddressResponse("Something went wrong. Please try again.");
                    }
                });
            }
        }
    }

    return (
        <>
            <div>
                <div>
                    <div>
                        {
                            addressResponse && <ErrorBanner message={addressResponse} setMessage={setAddressResponse} />
                        }
                    </div>
                    <div>
                        {
                            successAddressResponse && <SdfAlertBanner
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
                                    setSuccessAddressResponse(null);
                                }}
                            >
                                <span>{successAddressResponse}</span>
                            </SdfAlertBanner>
                        }
                    </div>
                </div>
            </div>
            <div style={rowStyle}>
                <div style={colStyle}>
                    <h3 className="text-heading-04 mt-4 mb-4">
                        {`${addressType.toString()}`}
                    </h3>
                </div>
            </div>
            <div style={rowStyle}>
                <div style={colStyle}>
                    <SdfSelectSimple
                        name="country"
                        id="demo-component"
                        label="Country"
                        onSdfChange={handleChange}
                        required-state={addressType === AddressType.CURRENT_ADDRESS ? "required" : "default"}
                        value={{ label: address.country }}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.country : profileInitialState.permanentAddress.country}
                        disabled={!edit && editable}
                        filterable=""
                    >
                        {countries.map((country) => (
                            <SdfSelectItem key={country.isoCode} value={country.isoCode}>{country.name}</SdfSelectItem>
                        ))}
                    </SdfSelectSimple>
                </div>
                <div style={colStyle}>
                    <SdfSelectSimple
                        id="demo-component"
                        label="State"
                        name="state"
                        filterable=""
                        input-width="2xl"
                        required-state={addressType === AddressType.CURRENT_ADDRESS ? "required" : "default"}
                        onSdfChange={handleChange}
                        disabled={!edit && editable || states.length == 0}
                        value={{ label: address.state }}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.state : profileInitialState.permanentAddress.state}
                    >
                        {states.length > 0 && states.map((state: IState) => (
                            <SdfSelectItem key={state.isoCode} value={state.isoCode}>{state.name}</SdfSelectItem>
                        ))}
                    </SdfSelectSimple>
                    {(edit && state.input.currentAddress.city === '' && states.length == 0 && edit && <InlineError message="First select country!" />)}
                </div>
                <div style={colStyle}>
                    <SdfSelectSimple
                        id="demo-component"
                        label="City"
                        name='city'
                        filterable=""
                        required-state={addressType === AddressType.CURRENT_ADDRESS ? "required" : "default"}
                        disabled={!edit && editable || cities.length == 0}
                        onSdfChange={handleChange}
                        value={{ label: address.city }}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.city : profileInitialState.permanentAddress.city}

                    >
                        {cities.map((city) => (

                            <SdfSelectItem key={city.name} value={city.name}>{city.name}</SdfSelectItem>

                        ))}
                    </SdfSelectSimple>
                    {(edit && state.input.currentAddress.city === '' && cities.length === 0 && <InlineError message="First select state and country!" />)}
                </div>

                <div style={colStyle}>
                    <SdfInput
                        label="Postal Code"
                        name='postal_code'
                        id="demo-component"
                        type="number"
                        className="w-full"
                        required-state={addressType === AddressType.CURRENT_ADDRESS ? "required" : "default"}
                        onSdfChange={handleChange}
                        value={address.postal_code}
                        placeholder={`${addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.postal_code : profileInitialState.permanentAddress.postal_code}`}

                        disabled={!edit && editable}
                    >
                    </SdfInput>
                </div>

            </div>

            <div style={rowStyle}>
                <div style={colStyle}>
                    <SdfTextarea label="Street Name" id="demo-component" cols="40" rows="3"
                        name="street"
                        value={address.street}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.street : profileInitialState.permanentAddress.street}

                    ></SdfTextarea>
                </div>

                <div style={colStyle}>
                    <SdfTextarea label="Address Line1" id="demo-component"
                        name="line_one"
                        cols="40" rows="3"
                        value={address.line_one}
                        onSdfChange={handleChange}
                        required-state={addressType === AddressType.CURRENT_ADDRESS ? "required" : "default"}
                        disabled={!edit && editable}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.line_one : profileInitialState.permanentAddress.line_one}

                    >

                    </SdfTextarea>
                </div>

                <div style={colStyle}>
                    <SdfTextarea label="Address Line 2" id="demo-component"
                        name="line_two"
                        cols="40" rows="3"
                        value={address.line_two}
                        onSdfChange={handleChange}
                        disabled={!edit && editable}
                        placeholder={addressType === AddressType.CURRENT_ADDRESS ? profileInitialState.currentAddress.line_two : profileInitialState.permanentAddress.line_two}

                    ></SdfTextarea>
                </div>
            </div>
            {edit && addressType === AddressType.PERMANENT_ADDRESS && <div className='flex space-x-4'>
                <SdfButton onClick={() => {
                    handleUpdate()
                    setEdit(false)
                }}>Update</SdfButton>
                <SdfButton onClick={() => {
                    dispatch({
                        type: 'RESET',
                        payload: { profileInitialState }
                    })
                    setEdit(false)
                    setCities([])
                    setStates([])
                }} action="destructive">Cancel</SdfButton>
            </div>}
        </>
    );
}
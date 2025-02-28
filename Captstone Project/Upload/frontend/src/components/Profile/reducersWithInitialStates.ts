import { useState, useEffect } from "react";
import axios from "axios";
import { EPerson, Gender, IAddress, IPerson, PersonAction } from "../../types.ts";

const initialAddress: IAddress = {
    address_type: "",
    city: "",
    country: "",
    line_one: "",
    line_two: "",
    postal_code: "",
    state: "",
    street: ""
};

const initialPersonError: EPerson = Object.freeze({
    email: null,
    currentAddress: null,
    permanentAddress: null,
    firstname: null,
    lastname: null,
    gender: null,
    dateofbirth: null,
    password: null,
    manager: null
});

const useProfileData = () => {
    const [personalDetails, setPersonalDetails] = useState({
        firstname: "",
        lastname: "",
        email: "",
        password: "",
        gender: Gender.MALE,
        dateofbirth: "",
        manager: ""
    });

    const [currentAddress, setCurrentAddress] = useState<IAddress>(initialAddress);
    const [permanentAddress, setPermanentAddress] = useState<IAddress>(initialAddress);

    useEffect(() => {
        axios
            .get("http://localhost:6769/api/employee/profile", {
                withCredentials: true
            })
            .then((response) => {
                const data = response.data;
                setPersonalDetails({
                    firstname: data.first_name,
                    lastname: data.last_name,
                    email: data.email,
                    password: "",
                    gender: response.data.gender,
                    dateofbirth: data.date_of_birth,
                    manager: data.manager
                });

                setCurrentAddress(data.address[0] || initialAddress);
                setPermanentAddress(data.address[1] || initialAddress);
            })
            .catch((error) => {
                console.error("Error fetching data: ", error);
            });
    }, []);

    const profileInitialState: IPerson = {
        firstname: personalDetails.firstname,
        lastname: personalDetails.lastname,
        email: personalDetails.email,
        password: "",
        manager: personalDetails.manager,
        currentAddress: currentAddress,
        permanentAddress: permanentAddress,
        gender: personalDetails.gender,
        dateofbirth: personalDetails.dateofbirth
    };

    return { profileInitialState, personalDetails, currentAddress, permanentAddress };
};

const profileReducer: React.Reducer<{ input: IPerson; error: EPerson }, PersonAction> = (state, action) => {
    switch (action.type) {
        case "SET_PERSONAL_DETAILS": {
            return { ...state, input: { ...state.input, [action.field]: action.value } };
        }
        case "SET_CURRENT_ADDRESS": {
            return { ...state, input: { ...state.input, currentAddress: { ...state.input.currentAddress, [action.field]: action.value } } };
        }
        case "SET_PERMANENT_ADDRESS": {
            return { ...state, input: { ...state.input, permanentAddress: { ...state.input.permanentAddress, [action.field]: action.value } } };
        }
        case "ERROR_PERSONAL_DETAILS": {
            return { ...state, error: { ...state.error, [action.field]: action.value } };
        }
        case "RESET": {
            return { input: action.payload.profileInitialState, error: initialPersonError };
        }
        default:
            return { input: action.payload.profileInitialState, error: initialPersonError };
    }
};

export { initialAddress, initialPersonError, useProfileData, profileReducer };
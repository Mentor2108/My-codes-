import { useState } from "react";
import axios, { AxiosError, AxiosResponse } from "axios";
import { useNavigate } from "react-router-dom";
import { useUser } from "../components/UserState.tsx";
import { defaultUserDetails, User } from "../types.ts";
import { LogoutError } from "../components/LogoutError.tsx";

export default function LogoutPage() {
    const navigate = useNavigate()
    const { userDetails, setUserDetails } = useUser();
    const [logoutResponse, setLogoutResponse] = useState<string | null>(null);

    !userDetails.currentUser && navigate(-1);

    axios.get('http://localhost:6769/auth/logout', {
        withCredentials: true
    }).then((response: AxiosResponse<User>) => {
        if (response.status && response.status === 200) {
            setUserDetails(defaultUserDetails);
            navigate('/login', { replace: true });
        } else {
            navigate(-1);
            setLogoutResponse("Something went wrong. Please try again.");
        }
    }).catch((error: AxiosError) => {
        navigate(-1);
        setLogoutResponse("Something went wrong. Please try again.");
    });

    return <LogoutError message={logoutResponse} />;
}
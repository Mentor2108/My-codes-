import { useEffect } from "react";
import { useUser } from "../components/UserState.tsx";
import axios, { AxiosResponse } from "axios";
import { User, LoadingProp } from "../types.ts";

export default function ValidateUser({ setLoading }: LoadingProp) {
    const { userDetails, updateCurrentUser } = useUser();

    useEffect(() => {
        const validateLogin = async () => {
            try {
                const response: AxiosResponse<User> = await axios.get('http://localhost:6769/api/employee/profile', {
                    withCredentials: true
                });

                if (response.status && response.status === 200) {
                    updateCurrentUser(response.data);
                } else {
                    updateCurrentUser(null);
                }
            } catch (error) {
                updateCurrentUser(null);
            } finally {
                setLoading(false);
            }
        }

        if (!userDetails.currentUser) validateLogin();
    }, [userDetails.currentUser])
}
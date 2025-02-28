import axios, { AxiosResponse } from "axios";
import { LoadingProp, User, UserDetails } from "../types.ts";

export default function PopulateUserDetails(loading: boolean, {setLoading}: LoadingProp, setUserDetails, updateManagedUsers) {
    // const { setUserDetails, updateManagedUsers } = useUser();

    const setUserDetailsAsync = (updateFunc: (prev: UserDetails) => UserDetails) => {
        return new Promise<void>((resolve) => {
            setUserDetails((prev) => {
                const newState = updateFunc(prev);
                resolve();
                return newState;
            });
        });
    };

    // useEffect(() => {
    const populateManagedUsers = async () => {
        let updatedUserDetails: { current_employee: User, managed_employee: User[] };
        try {
            const client = axios.create({ baseURL: "http://localhost:6769/api/employee/list/data" });
            const response: AxiosResponse<{ current_employee: User, managed_employee: User[] }> = await client({
                method: "GET",
                withCredentials: true
            });

            if (response.status && response.status === 200) {
                updatedUserDetails = response.data;
            } else {
                updateManagedUsers(null);
            }
        } catch (error) {
            console.error("managed users found error: ", error);
            updateManagedUsers(null);
        } finally {
            await setUserDetailsAsync((prev) => ({
                managedEmployees: updatedUserDetails.managed_employee,
                currentUser: updatedUserDetails.current_employee
            }))
        }
    }

    populateManagedUsers().then(() => {
        setLoading(false)
    }).catch((err) =>
        console.error("unexepected error: ", err)
    )
    // }, []);
}

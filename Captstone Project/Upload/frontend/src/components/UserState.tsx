import { useContext, useState, createContext, useEffect } from 'react';
import { User, UserDetails, UserDetailsContextProps, defaultUserDetails } from '../types.ts';

const UserContext = createContext<UserDetailsContextProps | undefined>(undefined);

export const UserProvider: React.FC<{ children: React.ReactNode }> = ({ children }) => {
    const [userDetails, setUserDetails] = useState<UserDetails>(defaultUserDetails);

    const updateCurrentUser = (user: User | null) => {
        setUserDetails((prev) => ({
            ...prev,
            currentUser: user
        }));
    };

    const updateManagedUsers = (managedUsers: User[]) => {
        setUserDetails((prev) => ({
            ...prev,
            managedEmployees: managedUsers
        }));
    };

    return (
        <UserContext.Provider value={{ userDetails, setUserDetails, updateCurrentUser, updateManagedUsers }}>
            {children}
        </UserContext.Provider>
    );
};

export const useUser = () => {
    const context = useContext(UserContext);
    if (!context) {
        throw new Error('useUser must be used within a UserProvider');
    }
    return context;
}
export enum Gender {
    MALE = "MALE",
    FEMALE = "FEMALE",
    OTHER = "OTHER"
};

export enum AddressType {
    PERMANENT_ADDRESS = "Permanent Address", 
    CURRENT_ADDRESS = "Current Address"
};

export enum ExpenseType {
    FOOD = "FOOD",
    RELOCATION = "RELOCATION",
    FLIGHT = "FLIGHT",
    WIFI = "WIFI",
    MOBILE_BILL = "MOBILE_BILL",
    OUTING = "OUTING"
}

export enum TravelType {
    INTERCITY_WITH_FAMILY = "INTERCITY_WITH_FAMILY",
    INTERCITY_WITHOUT_FAMILY = "INTERCITY_WITHOUT_FAMILY",
    INTRACITY_WITH_FAMILY = "INTRACITY_WITH_FAMILY",
    INTRACITY_WITHOUT_FAMILY = "INTRACITY_WITHOUT_FAMILY"
}

export enum ExpenseStatus {
    WAITING_FOR_APPROVAL = "WAITING_FOR_APPROVAL",
    REJECTED = "REJECTED",
    APPROVED = "APPROVED",
    PAID = "PAID"
}

export type Address = {
    street: string;
    city: string;
    state: string;
    country: string;
    address_type: string;
    line_one: string;
    line_two: string;
    postal_code: string;
}

export type User = {
    id: string;
    first_name: string;
    last_name: string;
    email: string;
    address: Address[];
    gender: Gender;
    date_of_birth: Date;
    manager_id: string;
    expense: Expense[];
};

export interface Expense {
    id: string;
    employee_name: string;
    expense_type: ExpenseType;
    date_of_expense: Date;
    from_location: string;
    to_location: string;
    travel_type: TravelType;
    amount: number;
    file: FileMetadata[];
    additional_comments: string;
    expense_status: ExpenseStatus;
    remarks: string;
};

export type FileMetadata = {
    id: string;
    file_name: string;
    file_path: string;
    file_size: number;
    file_type: string;
};

export interface UserDetails {
    currentUser: User | null;
    managedEmployees: User[];
}

export interface UserDetailsContextProps {
    userDetails: UserDetails;
    setUserDetails: React.Dispatch<React.SetStateAction<UserDetails>>;
    updateCurrentUser: (currentUser: User | null) => void;
    updateManagedUsers: (managedEmployees: User[]) => void;
    userProfileData: IPerson
}

export const defaultUserDetails: UserDetails = {
    currentUser: null,
    managedEmployees: [],
};

export interface LoadingProp {
    setLoading: React.Dispatch<React.SetStateAction<boolean>>
}

export interface Report {
    name: string,
    status: ExpenseStatus,
    expenseType: ExpenseType
    dateOfExpense: Date
    amount: number
    // file: File
}

export interface LoginState {
    email: string;
    password: string;
}

export interface LoginErrorState {
    email: string | null;
    password: string | null;
}

export type LoginAction = { type: "SET_INPUT", field: keyof LoginState, value: string }
    | { type: "SET_ERROR", field: keyof LoginErrorState, value: string | null }
    | { type: "RESET" };

export type IPerson = {
    email: string;
    firstname: string;
    lastname: string;
    gender: Gender;
    dateofbirth: string;
    password: string;
    manager: string;
    currentAddress: IAddress;
    permanentAddress: IAddress;
}

export type EPerson = {
    email: string | null;
    firstname: string | null;
    lastname: string | null;
    gender: Gender | null;
    dateofbirth: string | null;
    password: string | null;
    manager: string | null;
    currentAddress: IAddress | null;
    permanentAddress: IAddress | null;
}

export interface IAddress {
    street: string;
    city: string;
    state: string;
    country: string;
    address_type: string;
    line_one: string;
    line_two: string;
    postal_code: string;
}

export type PersonErrorState = {
    email: string | null;
    currentAddress: IAddress | null,
    permanentAddress: IAddress | null,
    firstname: string | null,
    lastname: string | null,
    gender: Gender | null,
    dateofbirth: string | null,
    password: string | null,
    manager: string | null
}

export type PersonAction =  { type: 'SET_PERSONAL_DETAILS', field: keyof IPerson, value: string } |
                            { type: 'ERROR_PERSONAL_DETAILS', field: keyof EPerson, value: string } |
                            { type: 'SET_CURRENT_ADDRESS', field: keyof IAddress, value: string } |
                            { type: 'SET_PERMANENT_ADDRESS', field: keyof IAddress, value: string } |
                            {
                              payload: any; type: 'RESET' }

export interface BarDataProps {
    food: number;
    flight: number;
    mobile_bill: number;
    outing: number;
    relocation: number;
    wifi: number;
    date_of_expense: Date;
}

export interface PieProp{
    idx: number;
    type: string;
    amount: number;
    count: number;
    color: string;
}
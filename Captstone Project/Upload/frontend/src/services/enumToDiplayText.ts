import { ExpenseStatus, ExpenseType } from "../types.ts";

export function GetExpenseTypeFromEnum(expenseType: ExpenseType) {
    let returnString: string
    switch (expenseType) {
        case ExpenseType.FLIGHT:
            returnString = "Flight";
            break;
        case ExpenseType.FOOD:
            returnString = "Food";
            break;
        case ExpenseType.MOBILE_BILL:
            returnString = "Mobile Bill";
            break;
        case ExpenseType.OUTING:
            returnString = "Outing";
            break;
        case ExpenseType.RELOCATION:
            returnString = "Relocation";
            break;
        case ExpenseType.WIFI:
            returnString = "Wi-Fi";
            break;
    }
    return returnString
}

export function GetExpenseStatusFromEnum(expenseStatus: ExpenseStatus) {
    let returnString: string
    switch (expenseStatus) {
        case ExpenseStatus.APPROVED:
            returnString ="Approved";
            break;
        case ExpenseStatus.WAITING_FOR_APPROVAL:
            returnString ="Pending";
            break;
        case ExpenseStatus.PAID:
            returnString ="Paid";
            break;
        case ExpenseStatus.REJECTED:
            returnString ="Rejected";
            break;
    }
    return returnString
}
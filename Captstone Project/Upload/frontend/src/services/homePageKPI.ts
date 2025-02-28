import { useUser } from "../components/UserState.tsx";
import { BarDataProps, Expense, ExpenseStatus, ExpenseType, PieProp } from "../types.ts";
import { GetExpenseStatusFromEnum } from "./enumToDiplayText.ts";

export function GetCurrentEmployeeExpenses(): Expense[] {
    const { userDetails } = useUser();

    const CurrentEmployeeExpenseList: Expense[] = []

    if (userDetails.currentUser.expense) {
        userDetails.currentUser.expense.forEach(expense => {
                CurrentEmployeeExpenseList.push(expense)
        })
    }
    return CurrentEmployeeExpenseList;
}


export function GetCurrentEmployeeExpensesByStatus(expenseStatus: ExpenseStatus): Expense[] {
    const { userDetails } = useUser();

    const CurrentExpenseListByStatus: Expense[] = []

    if (userDetails.currentUser.expense) {
        userDetails.currentUser.expense.forEach(expense => {
            if (expense.expense_status == expenseStatus) {
                CurrentExpenseListByStatus.push(expense)
            }
        })
    }
    return CurrentExpenseListByStatus;
}

export function GetManagedEmployeeExpenses(): Expense[] {
    const { userDetails } = useUser();

    const ManagedEmployeeExpenseList: Expense[] = []

    if (userDetails.managedEmployees) {
        userDetails.managedEmployees.forEach(managedEmployee => {
            if (managedEmployee.expense) {
                managedEmployee.expense.forEach(expense => {
                    ManagedEmployeeExpenseList.push(expense)
                })
            }
        })
    }
    return ManagedEmployeeExpenseList;
}

export function GetManagedEmployeeExpensesByStatus(expenseStatus: ExpenseStatus): Expense[] {
    const ManagedEmployeeExpenseList: Expense[] = []

    const expenseList = GetManagedEmployeeExpenses()
    if (expenseList) {
        expenseList.forEach(expense => {
            if (expense.expense_status == expenseStatus) {
                ManagedEmployeeExpenseList.push(expense)
            }
        })
    }
    return ManagedEmployeeExpenseList;
}

export function GetExpensesByStatus(expenseStatus: ExpenseStatus): Expense[] {
    const { userDetails } = useUser();

    const EmployeeExpenseList: Expense[] = []

    const expenseList = userDetails.currentUser.expense
    if (expenseList) {
        expenseList.forEach(expense => {
            if (expense.expense_status == expenseStatus) {
                EmployeeExpenseList.push(expense)
            }
        })
    }
    return EmployeeExpenseList;
}

export function FilterExpensesByStatus(expenseList: Expense[], expenseStatus: ExpenseStatus): Expense[] {
    if (!expenseList) {
        return []
    }
    const FilteredExpensesList: Expense[] = []

    expenseList.forEach(expense => {
        if (expense.expense_status === expenseStatus) {
            FilteredExpensesList.push(expense)
        }
    })
    return FilteredExpensesList;
}

export function GetTotalAmountForExpenses(expenseList: Expense[]): number {
    let totalAmount = 0;
    expenseList.forEach(expense => {
        totalAmount += expense.amount;
    })
    return totalAmount
}

export function GetExpensesBetweenDates(fromDate: Date, toDate: Date, data: Expense[]) {
    const filteredData = data.filter((expense) => {
        const currDate = new Date(expense.date_of_expense);
        return currDate >=fromDate && currDate<=toDate
    })
    const types = Object.keys(ExpenseType).map((value)=> value.toLowerCase())
    
    const groupedExpenses:BarDataProps[] = Object.values(filteredData.reduce((acc, expense)=>{
        const {date_of_expense, amount, expense_type} = expense;
        const dateKey = date_of_expense.toString()
        if (!acc[dateKey]) {
            acc[dateKey] = { date_of_expense, ...Object.fromEntries(types.map(t => [t, 0])) }
        }
        acc[dateKey][expense_type.toLowerCase()] = (acc[dateKey][expense_type.toLowerCase()] || 0) + amount;
        return acc;
    }, {}))
    return groupedExpenses.sort((a:BarDataProps, b:BarDataProps)=> new Date(a.date_of_expense).getTime() - new Date(b.date_of_expense).getTime())
}

const colors = { pending: "#804005", rejected: "#f78c8a", approved: "#d0c3f3", paid: "#78d479" }

const getColor = (expenseStatus: ExpenseStatus) => {
    switch (expenseStatus) {
        case ExpenseStatus.APPROVED: return colors['approved'];
        case ExpenseStatus.PAID: return colors['paid'];
        case ExpenseStatus.REJECTED: return colors['rejected'];
        case ExpenseStatus.WAITING_FOR_APPROVAL: return colors['pending']
    }
}

export function GetPieChartData() {
    const pendingExpenses = GetExpensesByStatus(ExpenseStatus.WAITING_FOR_APPROVAL)
    const rejectedExpenses = GetExpensesByStatus(ExpenseStatus.REJECTED)
    const approvedExpenses = GetExpensesByStatus(ExpenseStatus.APPROVED)
    const paidExpenses = GetExpensesByStatus(ExpenseStatus.PAID)
    let ct = 0;

    const result: PieProp[] = []

    result.push({ idx: ct++, type: GetExpenseStatusFromEnum(ExpenseStatus.WAITING_FOR_APPROVAL), amount: GetTotalAmountForExpenses(pendingExpenses), count: pendingExpenses.length, color: getColor(ExpenseStatus.WAITING_FOR_APPROVAL) })
    result.push({ idx: ct++, type: GetExpenseStatusFromEnum(ExpenseStatus.APPROVED), amount: GetTotalAmountForExpenses(approvedExpenses), count: approvedExpenses.length, color: getColor(ExpenseStatus.APPROVED) })
    result.push({ idx: ct++, type: GetExpenseStatusFromEnum(ExpenseStatus.REJECTED), amount: GetTotalAmountForExpenses(rejectedExpenses), count: rejectedExpenses.length, color: getColor(ExpenseStatus.REJECTED) })
    result.push({ idx: ct++, type: GetExpenseStatusFromEnum(ExpenseStatus.PAID), amount: GetTotalAmountForExpenses(paidExpenses), count: paidExpenses.length, color: getColor(ExpenseStatus.PAID) })

    return result;
}


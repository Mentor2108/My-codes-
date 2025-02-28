package com.adp.expense_management.exception;

public class ExpenseNotFoundException extends ExpenseException{
	public ExpenseNotFoundException() {
        super("Expense Not Found");
    }

    public ExpenseNotFoundException(String message) {
        super(message);
    }

    public ExpenseNotFoundException(String message, Throwable t) {
        super(message,t);
    }
}

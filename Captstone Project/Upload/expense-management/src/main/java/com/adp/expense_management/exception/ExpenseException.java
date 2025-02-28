package com.adp.expense_management.exception;

public class ExpenseException extends Exception{
	public ExpenseException() {
        super("Expense Exception");
    }

    public ExpenseException(String message) {
        super(message);
    }

    public ExpenseException(String message, Throwable t) {
        super(message,t);
    }
}

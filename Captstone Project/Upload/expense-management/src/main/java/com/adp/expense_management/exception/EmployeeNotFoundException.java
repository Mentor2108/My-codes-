package com.adp.expense_management.exception;

public class EmployeeNotFoundException extends EmployeeException {
	public EmployeeNotFoundException() {
        super("Employee Not Found");
    }

    public EmployeeNotFoundException(String message) {
        super(message);
    }

    public EmployeeNotFoundException(String message, Throwable t) {
        super(message,t);
    }
}
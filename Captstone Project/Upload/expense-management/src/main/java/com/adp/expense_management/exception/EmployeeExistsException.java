package com.adp.expense_management.exception;

public class EmployeeExistsException extends EmployeeException{
    public EmployeeExistsException() {
        super("EmployeeExistsException");
    }

    public EmployeeExistsException(String message) {
        super(message);
    }

    public EmployeeExistsException(String message, Throwable t) {
        super(message,t);
    }
}
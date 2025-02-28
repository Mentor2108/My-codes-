package com.adp.expense_management.exception;

public class EmployeeException extends Exception{
    public EmployeeException() {
        super("EmployeeException");
    }

    public EmployeeException(String message) {
        super(message);
    }

    public EmployeeException(String message, Throwable t) {
        super(message,t);
    }
}
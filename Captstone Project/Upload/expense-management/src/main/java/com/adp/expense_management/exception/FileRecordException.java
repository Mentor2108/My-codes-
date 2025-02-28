package com.adp.expense_management.exception;

public class FileRecordException extends Exception{
    public FileRecordException() {
        super("FileRecord Exception");
    }

    public FileRecordException(String message) {
        super(message);
    }

    public FileRecordException(String message, Throwable t) {
        super(message,t);
    }
}

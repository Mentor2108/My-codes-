package com.adp.auth.exception;

public class AuthenticationException extends Exception{
    public AuthenticationException() {
        super("AuthenticationException");
    }

    public AuthenticationException(String message) {
        super(message);
    }

    public AuthenticationException(String message, Throwable t) {
        super(message,t);
    }
}
package com.adp.expense_management.exception;

import com.adp.expense_management.model.WrappedErrorResponse;
import lombok.extern.slf4j.Slf4j;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.dao.DataAccessException;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.method.annotation.MethodArgumentConversionNotSupportedException;
import org.springframework.web.method.annotation.MethodArgumentTypeMismatchException;
import org.springframework.web.server.MethodNotAllowedException;
import org.springframework.web.server.ResponseStatusException;
import org.springframework.web.servlet.resource.NoResourceFoundException;

import java.io.IOException;
import java.nio.file.InvalidPathException;
import java.util.stream.Collectors;


@RestControllerAdvice
@Slf4j
public class GlobalExceptionHandlers {

    @ExceptionHandler(value = MethodArgumentNotValidException.class)
    public ResponseEntity<WrappedErrorResponse> handleValidationException(MethodArgumentNotValidException exception) {
        String errorMessage = exception.getBindingResult()
                .getFieldErrors()
                .stream()
                .map(error -> error.getField() + ": " + error.getDefaultMessage())
                .collect(Collectors.joining(", "));
        log.error("Validation Error: {}", errorMessage);
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(new WrappedErrorResponse("Validation Error", errorMessage));
    }

    @ExceptionHandler(value = {MethodArgumentTypeMismatchException.class, MethodArgumentConversionNotSupportedException.class})
    public ResponseEntity<WrappedErrorResponse> handleMethodArgumentException(Exception exception) {
        log.error("MethodArgumentException Error: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(new WrappedErrorResponse("Validation Error", exception.getMessage()));
    }

    @ExceptionHandler(EmployeeNotFoundException.class)
    public ResponseEntity<WrappedErrorResponse> handleEmployeeNotFoundException(EmployeeNotFoundException exception) {
        log.error("Employee Not Found: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(new WrappedErrorResponse("Employee Not Found", exception.getMessage()));
    }

    @ExceptionHandler(DataIntegrityViolationException.class)
    public ResponseEntity<WrappedErrorResponse> handleDuplicateEntryException(DataIntegrityViolationException exception) {
        String message = "Duplicate Entry: " +
                (exception.getMostSpecificCause() != null ? exception.getMostSpecificCause().getMessage() : exception.getMessage());
        log.error(message);
        return ResponseEntity.status(HttpStatus.CONFLICT).body(new WrappedErrorResponse("Duplicate Entry", message));
    }

    @ExceptionHandler(EmployeeExistsException.class)
    public ResponseEntity<WrappedErrorResponse> handleEmployeeExistsException(EmployeeExistsException exception) {
        log.error("Employee Exists: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.CONFLICT).body(new WrappedErrorResponse("Duplicate Entry", exception.getMessage()));
    }

    @ExceptionHandler(AccessDeniedException.class)
    public ResponseEntity<WrappedErrorResponse> handleAccessDeniedException(AccessDeniedException exception) {
        log.warn("Access Denied: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.FORBIDDEN).body(new WrappedErrorResponse("Access Denied", exception.getMessage()));
    }

    @ExceptionHandler(value = {IOException.class, SecurityException.class, InvalidPathException.class})
    public ResponseEntity<WrappedErrorResponse> handleIOException(Exception exception) {
        log.error("File Handling Error: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(new WrappedErrorResponse("File Handling Error", exception.getMessage()));
    }

    @ExceptionHandler(EmployeeException.class)
    public ResponseEntity<WrappedErrorResponse> handleException(EmployeeException exception) {
        log.error("Employee Exception: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(new WrappedErrorResponse("Employee Exception", exception.getMessage()));
    }

    @ExceptionHandler(ClassCastException.class)
    public ResponseEntity<WrappedErrorResponse> handleClassCastException(ClassCastException exception) {
        log.error("Error in Class Cast: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(new WrappedErrorResponse("Error in Class Cast", exception.getMessage()));
    }

    @ExceptionHandler(NoResourceFoundException.class)
    public ResponseEntity<WrappedErrorResponse> handleNoResourceFoundException(NoResourceFoundException exception) {
        log.error("Error in Request: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.NOT_FOUND).body(new WrappedErrorResponse("Error in Request", exception.getMessage()));
    }

    @ExceptionHandler(MethodNotAllowedException.class)
    public ResponseEntity<WrappedErrorResponse> handleMethodNotAllowedException(MethodNotAllowedException exception) {
        log.error("Error in Request Method: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.METHOD_NOT_ALLOWED).body(new WrappedErrorResponse("Error in Request Method", exception.getMessage()));
    }

    @ExceptionHandler(NullPointerException.class)
    public ResponseEntity<WrappedErrorResponse> handleNullPointerException(NullPointerException exception) {
        log.error("Error while handling data (Null value): {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(new WrappedErrorResponse("Error while handling null values", exception.getMessage()));
    }


    @ExceptionHandler(DataAccessException.class)
    public ResponseEntity<WrappedErrorResponse> handleDataAccessException(DataAccessException exception) {
        log.error("Database Error: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(new WrappedErrorResponse("Database Error", exception.getMessage()));
    }

    @ExceptionHandler(ResponseStatusException.class)
    public ResponseEntity<WrappedErrorResponse> handleResponseStatusException(ResponseStatusException exception) {
        log.error("Error Perfoming Action: {}", exception.getMessage());
        return ResponseEntity.status(exception.getStatusCode()).body(new WrappedErrorResponse("Error Perfoming Action", exception.getMessage()));
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<WrappedErrorResponse> handleException(Exception exception) {
        log.error("An Unexpected Error Occured: {}", exception.getMessage());
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(new WrappedErrorResponse("Internal Server Error", exception.getMessage()));
    }
}
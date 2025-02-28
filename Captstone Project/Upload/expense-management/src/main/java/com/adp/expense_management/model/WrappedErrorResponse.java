package com.adp.expense_management.model;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.time.LocalDateTime;

@Getter
@Setter
public class WrappedErrorResponse {
	private ErrorResponse error;
	private LocalDateTime timestamp;
	
	public WrappedErrorResponse(String errorMessage, String errorDetails) {
		super();
		this.error = new ErrorResponse(errorMessage, errorDetails);
		this.timestamp = LocalDateTime.now();
	}
}

@Getter
@Setter
@AllArgsConstructor
class ErrorResponse {
	private String message;
	private String detail;
}
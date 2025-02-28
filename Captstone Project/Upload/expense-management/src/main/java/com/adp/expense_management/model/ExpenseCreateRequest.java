package com.adp.expense_management.model;

import java.time.LocalDate;

import com.adp.expense_management.entity.ExpenseType;
import com.adp.expense_management.entity.TravelType;
import com.fasterxml.jackson.annotation.JsonProperty;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;

public record ExpenseCreateRequest(
		@NotNull
		@JsonProperty("expense_type") ExpenseType expenseType,

		@NotNull
		@JsonProperty("date_of_expense") LocalDate dateOfExpense,

		@JsonProperty("from_location") String fromLocation,

		@JsonProperty("to_location") String toLocation,

		@JsonProperty("travel_type") TravelType travelType,
		
		@NotBlank
		@JsonProperty("employee_id") String employeeId,

		@NotNull
		Float amount,
		
		@JsonProperty("additional_comments") String additionalComments
		
		) {
}

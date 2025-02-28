package com.adp.expense_management.model;

import java.time.LocalDate;
import java.util.List;

import com.adp.expense_management.constraints.ExtendedEmailValidator;
import com.adp.expense_management.constraints.ValidationFailedMessage;
import com.adp.expense_management.entity.Gender;
import com.fasterxml.jackson.annotation.JsonProperty;

import jakarta.validation.constraints.NotNull;

public record EmployeeUpdate(
		@JsonProperty("first_name")
		String firstName,

        @JsonProperty("last_name")
        String lastName,

        @ExtendedEmailValidator
        String email,

        @JsonProperty("date_of_birth")
        LocalDate dateOfBirth,

        @JsonProperty("address")
        List<AddressModel> addressList,

        @NotNull(message = ValidationFailedMessage.GENDER)
        Gender gender

		) {

}

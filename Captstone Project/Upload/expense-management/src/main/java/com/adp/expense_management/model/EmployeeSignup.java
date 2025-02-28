package com.adp.expense_management.model;

import java.time.LocalDate;
import java.util.List;

import com.adp.expense_management.constraints.ExtendedEmailValidator;
import com.adp.expense_management.constraints.ValidationFailedMessage;
import com.adp.expense_management.entity.Gender;
import com.fasterxml.jackson.annotation.JsonProperty;

import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

public record EmployeeSignup(
        @JsonProperty("first_name")
        @NotBlank(message = ValidationFailedMessage.FIRST_NAME)
        String firstName,

        @JsonProperty("last_name")
        String lastName,

        @ExtendedEmailValidator
        String email,

        @Size(min = 6, message = ValidationFailedMessage.PASSWORD)
        String password,

        @JsonProperty("date_of_birth")
        LocalDate dateOfBirth,

        @JsonProperty("address")
        List<AddressModel> addressList,

        @NotNull(message = ValidationFailedMessage.GENDER)
        Gender gender,

        @NotBlank(message = ValidationFailedMessage.MANAGER_ID)
        @JsonProperty("manager_id")
        String managerId) {
}
package com.adp.auth.model;

import com.adp.auth.constraints.ExtendedEmailValidator;
import com.adp.auth.constraints.ValidationFailedMessage;
import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;

import java.time.LocalDate;
import java.util.List;

//Need to take input of address in the end
public record EmployeeSignupRequest(
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
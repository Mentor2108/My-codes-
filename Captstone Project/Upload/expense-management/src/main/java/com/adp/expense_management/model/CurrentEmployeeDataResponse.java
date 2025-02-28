package com.adp.expense_management.model;

import java.util.List;

import com.fasterxml.jackson.annotation.JsonProperty;

public record CurrentEmployeeDataResponse(
        @JsonProperty("current_employee")
        EmployeeResponse currentEmployee,

        @JsonProperty("managed_employee")
        List<EmployeeResponse> managedEmployees) {
}

package com.adp.expense_management.model;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.adp.expense_management.entity.EmployeeE;
import com.adp.expense_management.entity.Gender;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;

public record EmployeeResponse(
        String id,

        @JsonProperty("first_name") String firstName,

        @JsonProperty("last_name") String lastName,

        String email,

        @JsonProperty("date_of_birth") LocalDate dateOfBirth,

        List<AddressModel> address,

        Gender gender,

        @JsonProperty("manager_id") String managerId,

        @JsonInclude(JsonInclude.Include.NON_NULL)
        List<ExpenseResponse> expense) {

    public static EmployeeResponse getInstance(EmployeeE employee) {
        if (employee.getAddressList() == null) {
            employee.setAddressList(new ArrayList<>());
        }
        return new EmployeeResponse(
                employee.getId(),
                employee.getFirstName(),
                employee.getLastName(),
                employee.getEmail(),
                employee.getDateOfBirth(),
                employee.getAddressList().stream().map(AddressModel::getInstance).collect(Collectors.toList()),
                employee.getGender(),
                employee.getManager().getId(),
                null);
    }

    public static EmployeeResponse getInstanceWithExpense(EmployeeE employee) {
        if (employee.getAddressList() == null) {
            employee.setAddressList(new ArrayList<>());
        }
        if (employee.getExpenseList() == null) {
            employee.setExpenseList(new ArrayList<>());
        }
        return new EmployeeResponse(
                employee.getId(),
                employee.getFirstName(),
                employee.getLastName(),
                employee.getEmail(),
                employee.getDateOfBirth(),
                employee.getAddressList().stream().map(AddressModel::getInstance).collect(Collectors.toList()),
                employee.getGender(),
                employee.getManager().getId(),
                employee.getExpenseList().stream().map(ExpenseResponse::getInstance).collect(Collectors.toList()));
    }

    public static EmployeeResponse getInstanceWithExpenseWithFiles(EmployeeE employee) {
        if (employee.getAddressList() == null) {
            employee.setAddressList(new ArrayList<>());
        }
        if (employee.getExpenseList() == null) {
            employee.setExpenseList(new ArrayList<>());
        }
        return new EmployeeResponse(
                employee.getId(),
                employee.getFirstName(),
                employee.getLastName(),
                employee.getEmail(),
                employee.getDateOfBirth(),
                employee.getAddressList().stream().map(AddressModel::getInstance).collect(Collectors.toList()),
                employee.getGender(),
                employee.getManager().getId(),
                employee.getExpenseList().stream().map(ExpenseResponse::getInstanceWithFile).collect(Collectors.toList()));
    }

}

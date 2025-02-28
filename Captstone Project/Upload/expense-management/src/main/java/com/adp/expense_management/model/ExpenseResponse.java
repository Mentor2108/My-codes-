package com.adp.expense_management.model;

import com.adp.expense_management.entity.ExpenseE;
import com.adp.expense_management.entity.ExpenseStatus;
import com.adp.expense_management.entity.ExpenseType;
import com.adp.expense_management.entity.TravelType;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonInclude.Include;
import com.fasterxml.jackson.annotation.JsonProperty;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@JsonInclude(Include.NON_NULL)
public record ExpenseResponse(
        String id,

        @JsonProperty("employee_name") String employeName,

        @JsonProperty("expense_type") ExpenseType expenseType,

        @JsonProperty("date_of_expense") LocalDate dateOfExpense,

        @JsonProperty("from_location") String fromLocation,

        @JsonProperty("to_location") String toLocation,

        @JsonProperty("travel_type") TravelType travelType,

        Float amount,

        @JsonProperty("employee")
        EmployeeResponse employee,

        @JsonProperty("file")
        List<FileResponse> filesList,

        @JsonProperty("additional_comments") String additionalComments,

        @JsonProperty("expense_status") ExpenseStatus expenseStatus,

        String remarks) {

    public static ExpenseResponse getInstance(ExpenseE expense) {
        return new ExpenseResponse(
                expense.getId(),
                expense.getEmployee().getFirstName() + (expense.getEmployee().getLastName()!=null? " " + expense.getEmployee().getLastName(): ""),
                expense.getExpenseType(),
                expense.getDateOfExpense(),
                expense.getFromLocation(),
                expense.getToLocation(),
                expense.getTravelType(),
                expense.getAmount(),
                null,
                null,
                expense.getAdditionalComments(),
                expense.getExpenseStatus(),
                expense.getRemarks());
    }

    public static ExpenseResponse getInstanceWithEmployee(ExpenseE expense) {
        return new ExpenseResponse(
                expense.getId(),
                expense.getEmployee().getFirstName() + (expense.getEmployee().getLastName()!=null? " " + expense.getEmployee().getLastName(): ""),
                expense.getExpenseType(),
                expense.getDateOfExpense(),
                expense.getFromLocation(),
                expense.getToLocation(),
                expense.getTravelType(),
                expense.getAmount(),
                EmployeeResponse.getInstance(expense.getEmployee()),
                null,
                expense.getAdditionalComments(),
                expense.getExpenseStatus(),
                expense.getRemarks());
    }

    public static ExpenseResponse getInstanceWithFile(ExpenseE expense) {
        if (expense.getFileList() == null) {
            expense.setFileList(new ArrayList<>());
        }
        return new ExpenseResponse(
                expense.getId(),
                expense.getEmployee().getFirstName() + (expense.getEmployee().getLastName()!=null? " " + expense.getEmployee().getLastName(): ""),
                expense.getExpenseType(),
                expense.getDateOfExpense(),
                expense.getFromLocation(),
                expense.getToLocation(),
                expense.getTravelType(),
                expense.getAmount(),
                null,
                expense.getFileList().stream().map(FileResponse::getInstance).collect(Collectors.toList()),
                expense.getAdditionalComments(),
                expense.getExpenseStatus(),
                expense.getRemarks());
    }

}

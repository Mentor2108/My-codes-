package com.adp.expense_management.service;

import java.util.List;

import com.adp.expense_management.exception.EmployeeException;
import com.adp.expense_management.exception.EmployeeNotFoundException;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.ExpenseCreateRequest;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.model.ExpenseUpdateRequest;

public interface ExpenseService {

	ExpenseResponse getExpenseByExpenseId(String expenseId) throws ExpenseException;
	
	List<ExpenseResponse> getExpenseListByEmployeeId(String employeeId) throws ExpenseException, EmployeeException;
	
	ExpenseResponse createExpense(ExpenseCreateRequest expenseRequest) throws ExpenseException, EmployeeException;
	
	ExpenseResponse updateExpense(String expenseId, ExpenseUpdateRequest expenseRequest) throws ExpenseException;

	Boolean deleteExpenseById(String expenseId) throws ExpenseException;

	List<ExpenseResponse> getExpenseListByManagerId(String managerId) throws ExpenseException, EmployeeException;
}
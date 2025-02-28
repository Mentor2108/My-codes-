package com.adp.expense_management.service;

import java.util.List;

import com.adp.expense_management.exception.EmployeeException;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.*;

public interface EmployeeService {

	EmployeeLogin getLoginResponse(EmployeeLogin employeeLogin) throws EmployeeException;

	EmployeeResponse getSignupResponse(EmployeeSignup employeeSignup) throws EmployeeException;

	EmployeeResponse getEmployeeProfile() throws EmployeeException;

	EmployeeResponse getEmployeeById(String employeeId) throws EmployeeException;

	List<EmployeeResponse> getAllEmployees() throws EmployeeException;

	EmployeeResponse updateEmployeeById(String employeeId, EmployeeUpdate employeeDetails)
			throws EmployeeException;

	Boolean deleteEmployeeById(String id) throws EmployeeException;

	List<EmployeeResponse> getAllEmployeesByManagerId(String managerId) throws EmployeeException;

	CurrentEmployeeDataResponse getCurrentEmployeeData() throws EmployeeException;

}

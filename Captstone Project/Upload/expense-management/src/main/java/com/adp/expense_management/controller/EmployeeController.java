package com.adp.expense_management.controller;

import java.util.List;

import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.CurrentEmployeeDataResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import com.adp.expense_management.exception.EmployeeException;
import com.adp.expense_management.model.EmployeeResponse;
import com.adp.expense_management.model.EmployeeUpdate;
import com.adp.expense_management.service.EmployeeService;

import lombok.extern.slf4j.Slf4j;

@RestController
@RequestMapping("/api/employee")
@Slf4j
public class EmployeeController {

	@Autowired
	private EmployeeService employeeService;

	@GetMapping("/profile")
	public ResponseEntity<EmployeeResponse> getEmployeeProfile() {
		try {
			return new ResponseEntity<>(employeeService.getEmployeeProfile(), HttpStatus.OK);
		} catch (EmployeeException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@GetMapping("/id/{id}")
	public ResponseEntity<EmployeeResponse> getEmployeeById(@PathVariable("id") String employeeId) {
		try {
			return new ResponseEntity<>(employeeService.getEmployeeById(employeeId), HttpStatus.OK);
		} catch (EmployeeException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@GetMapping("/list")
	public ResponseEntity<List<EmployeeResponse>> getAllEmployees() {
		try {
			return new ResponseEntity<>(employeeService.getAllEmployees(), HttpStatus.OK);
		} catch (EmployeeException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@PutMapping("/update/id/{id}")
	public ResponseEntity<EmployeeResponse> updateEmployeeById(@PathVariable("id") String employeeId,
			@RequestBody EmployeeUpdate employeeDetails) {
		try {
			return new ResponseEntity<>(employeeService.updateEmployeeById(employeeId, employeeDetails), HttpStatus.OK);
		} catch (EmployeeException e) {
			throw new ResponseStatusException(HttpStatus.NOT_MODIFIED, e.getMessage());
		}
	}

//	@DeleteMapping("/delete/id/{id}")
//	public ResponseEntity<Map<String, Object>> deleteEmployeeById(@PathVariable("id") String employeeId) {
//		try {
//			return employeeService.deleteEmployeeById(employeeId) ? new ResponseEntity<>(Map.of("response", "Successfully Deleted"), HttpStatus.OK)
//					: new ResponseEntity<>(Map.of("error", "Cannot Delete Employee with Id: " + employeeId), HttpStatus.BAD_REQUEST);
//		} catch (EmployeeException e) {
//			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
//		}
//	}

	@GetMapping("/list/manager-id/{id}")
	public ResponseEntity<List<EmployeeResponse>> getAllEmployeesByManagerId(@PathVariable("id") String managerId)
			throws Exception {
		try {
			return new ResponseEntity<>(employeeService.getAllEmployeesByManagerId(managerId), HttpStatus.OK);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@GetMapping("/list/data")
	public ResponseEntity<CurrentEmployeeDataResponse> getCurrentEmployeeData()
			throws EmployeeException {
		try {
			return new ResponseEntity<>(employeeService.getCurrentEmployeeData(), HttpStatus.OK);
		} catch (EmployeeException e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}
}
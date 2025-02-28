package com.adp.expense_management.controller;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import com.adp.expense_management.exception.EmployeeException;
import com.adp.expense_management.exception.EmployeeExistsException;
import com.adp.expense_management.model.EmployeeLogin;
import com.adp.expense_management.model.EmployeeResponse;
import com.adp.expense_management.model.EmployeeSignup;
import com.adp.expense_management.service.EmployeeService;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@RestController
@RequestMapping("/api/employee")
@RequiredArgsConstructor
@Slf4j
public class LoginSignupController {
	private final EmployeeService employeeService;

	@PostMapping("/login")
	public ResponseEntity<EmployeeLogin> getLoginResponse(@RequestBody EmployeeLogin employeeLogin) {
		try {
			return new ResponseEntity<>(employeeService.getLoginResponse(employeeLogin), HttpStatus.OK);
		} catch (EmployeeException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@PostMapping("/signup")
	public ResponseEntity<EmployeeResponse> getSignupResponse(@RequestBody EmployeeSignup employeeSignup) {
		try {
			return new ResponseEntity<>(employeeService.getSignupResponse(employeeSignup), HttpStatus.OK);
		} catch (EmployeeExistsException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.CONFLICT, e.getMessage());
		} catch (EmployeeException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}
}

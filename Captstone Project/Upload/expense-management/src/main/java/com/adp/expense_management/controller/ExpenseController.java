package com.adp.expense_management.controller;

import java.util.List;
import java.util.Map;

import com.adp.expense_management.model.ExpenseUpdateRequest;
import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import com.adp.expense_management.model.ExpenseCreateRequest;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.service.ExpenseService;

@RestController
@RequestMapping("/api/expense")
public class ExpenseController {

	@Autowired
	private ExpenseService expenseService;

	@GetMapping("/id/{id}")
	public ResponseEntity<ExpenseResponse> getExpenseByExpenseId(@PathVariable("id") String expenseId) {
		try {
			return new ResponseEntity<>(expenseService.getExpenseByExpenseId(expenseId), HttpStatus.OK);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@GetMapping("/list/employee-id/{id}")
	public ResponseEntity<List<ExpenseResponse>> getExpenseListByEmployeeId(@PathVariable("id") String employeeId) {
		try {
			List<ExpenseResponse> expensesList = expenseService.getExpenseListByEmployeeId(employeeId);
			return new ResponseEntity<>(expensesList, HttpStatus.OK);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@PostMapping("/add")
	public ResponseEntity<ExpenseResponse> createExpense(@Valid @RequestBody ExpenseCreateRequest expenseRequest) {
		try {
			return new ResponseEntity<>(expenseService.createExpense(expenseRequest), HttpStatus.CREATED);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@PutMapping("/update/id/{id}")
	public ResponseEntity<ExpenseResponse> updateExpense(@PathVariable("id") String expenseId,
			@Valid @RequestBody ExpenseUpdateRequest expenseRequest) {
		try {
			return new ResponseEntity<>(expenseService.updateExpense(expenseId, expenseRequest), HttpStatus.OK);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.NOT_MODIFIED, e.getMessage());
		}
	}

	@DeleteMapping("/delete/id/{id}")
	public ResponseEntity<Map<String, Object>> deleteExpenseById(@PathVariable("id") String expenseId)
			throws Exception {
		try {
			return expenseService.deleteExpenseById(expenseId)
					? new ResponseEntity<>(Map.of("response", "Successfully Deleted"), HttpStatus.OK)
					: new ResponseEntity<>(Map.of("error", "Cannot Delete Expense with id: " + expenseId),
							HttpStatus.BAD_REQUEST);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@GetMapping("/list/manager-id/{id}")
	public ResponseEntity<List<ExpenseResponse>> getExpenseListByManagerId(@PathVariable("id") String managerId) {
		try {
			return new ResponseEntity<>(expenseService.getExpenseListByManagerId(managerId), HttpStatus.OK);
		} catch (Exception e) {
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}
}
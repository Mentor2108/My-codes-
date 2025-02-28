package com.adp.expense_management.service;

import com.adp.expense_management.entity.EmployeeE;
import com.adp.expense_management.entity.ExpenseE;
import com.adp.expense_management.entity.ExpenseStatus;
import com.adp.expense_management.exception.EmployeeException;
import com.adp.expense_management.exception.EmployeeNotFoundException;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.ExpenseNotFoundException;
import com.adp.expense_management.model.ExpenseCreateRequest;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.model.ExpenseUpdateRequest;
import com.adp.expense_management.repository.EmployeeRepository;
import com.adp.expense_management.repository.ExpenseRepository;
import com.adp.expense_management.repository.FileRecordRepository;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.BeansException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.stereotype.Service;
import org.springframework.web.client.ResourceAccessException;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

@Service
public class ExpenseServiceImpl implements ExpenseService {

    @Autowired
    private ExpenseRepository expenseRepository;

    @Autowired
    private FileRecordRepository fileRecordRepository;

    @Autowired
    private EmployeeRepository employeeRepository;

    @Autowired
    private EmployeeService employeeService;

    @Override
    public ExpenseResponse getExpenseByExpenseId(String expenseId) throws ExpenseException {
        try {
            ExpenseE expense = expenseRepository.findById(expenseId).orElseThrow();
            return ExpenseResponse.getInstanceWithEmployee(expense);
        } catch (NoSuchElementException e) {
            throw new ExpenseNotFoundException("Expense Not Found with Id: " + expenseId);
        } catch (DataAccessException e) {
            throw new ExpenseException("Database Error: " + e.getMessage());
        }
    }

    @Override
    public List<ExpenseResponse> getExpenseListByEmployeeId(String employeeId) throws ExpenseException, EmployeeException {
        try {
            List<ExpenseE> expenseList = employeeRepository.findById(employeeId).orElseThrow().getExpenseList();
            List<ExpenseResponse> expenseResponse = new ArrayList<>();

            for (ExpenseE expense : expenseList) {
                expenseResponse.add(ExpenseResponse.getInstance(expense));
            }
            return expenseResponse;
        } catch (NoSuchElementException e) {
            throw new EmployeeNotFoundException("Employee Not Found with Id: " + employeeId);
        } catch (DataAccessException e) {
            throw new ExpenseException("Database Error: " + e.getMessage());
        }
    }

    @Override
    public ExpenseResponse createExpense(ExpenseCreateRequest expenseRequest) throws ExpenseException, EmployeeException {
        try {
            ExpenseE expenseE = new ExpenseE();
            BeanUtils.copyProperties(expenseRequest, expenseE);
            expenseE.setEmployee(employeeRepository.findById(expenseRequest.employeeId()).orElseThrow());
            expenseE.setExpenseStatus(ExpenseStatus.WAITING_FOR_APPROVAL);
            expenseE = expenseRepository.save(expenseE);
            return ExpenseResponse.getInstanceWithEmployee(expenseE);
        } catch (NoSuchElementException e) {
            throw new EmployeeNotFoundException("Employee Not Found with Id: " + expenseRequest.employeeId());
        } catch (BeansException e) {
            throw new ExpenseException(e.getMessage(), e);
        }
    }

    @Override
    public ExpenseResponse updateExpense(String expenseId, ExpenseUpdateRequest newExpense) throws ExpenseException {
        try {
            ExpenseE oldExpense = expenseRepository.findById(expenseId).orElseThrow();
            BeanUtils.copyProperties(newExpense, oldExpense);
            return ExpenseResponse.getInstance(expenseRepository.save(oldExpense));
        } catch (NoSuchElementException e) {
            throw new ExpenseNotFoundException("Expense Not Found with Id: " + expenseId);
        } catch (BeansException e) {
            throw new ExpenseException(e.getMessage(), e);
        }
    }

	@Override
	public Boolean deleteExpenseById(String expenseId) throws ExpenseException{
		try {
            ExpenseE expense = expenseRepository.findById(expenseId).orElseThrow();
            expense.getFileList().forEach(file -> {
                fileRecordRepository.deleteById(file.getId());
            });
            expenseRepository.deleteById(expenseId);
            return true;
		} catch (NoSuchElementException e) {
            throw new ExpenseNotFoundException("Expense Not Found with Id: " + expenseId);
		} catch (Exception e) {
            throw new ResourceAccessException(e.getMessage());
        }
	}
		
	@Override
	public List<ExpenseResponse> getExpenseListByManagerId(String managerId) throws ExpenseException, EmployeeException{
		try {
			List<EmployeeE> employeeList = employeeRepository.findByManagerId(managerId).orElseThrow();
			List<ExpenseResponse> expenseResponse = new ArrayList<>();
			for(EmployeeE employee : employeeList) {
				List<ExpenseE> expenseList = employee.getExpenseList();
                if (expenseList == null) {
                    continue;
                }
				for(ExpenseE expense : expenseList) {
					expenseResponse.add(ExpenseResponse.getInstanceWithEmployee(expense));
				}
			}
			return expenseResponse;
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Manager not found with id: " + managerId);
		} catch (DataAccessException e) {
            throw new ExpenseException("Database Error: " + e.getMessage());
		}
	}
}
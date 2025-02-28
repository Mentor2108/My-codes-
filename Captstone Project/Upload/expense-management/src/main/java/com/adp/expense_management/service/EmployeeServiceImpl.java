package com.adp.expense_management.service;

import com.adp.expense_management.entity.Address;
import com.adp.expense_management.entity.EmployeeE;
import com.adp.expense_management.exception.*;
import com.adp.expense_management.model.*;
import com.adp.expense_management.repository.AddressRepository;
import com.adp.expense_management.repository.EmployeeRepository;
import com.adp.expense_management.repository.ExpenseRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.BeansException;
import org.springframework.dao.DataAccessException;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;

@Service
@RequiredArgsConstructor
@Transactional
@Slf4j
public class EmployeeServiceImpl implements EmployeeService {

	private final EmployeeRepository employeeRepository;
	private final ExpenseRepository expenseRepository;
	private final AddressRepository addressRepository;

//    private BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

	@Override
	public EmployeeLogin getLoginResponse(EmployeeLogin employeeLogin) throws EmployeeException {
		try {
			EmployeeE employee = employeeRepository.findByEmail(employeeLogin.email()).orElseThrow();
			return new EmployeeLogin(employee.getEmail(), employee.getPassword());
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("No employee found with email: " + employeeLogin.email(), e);
		} catch (DataIntegrityViolationException e) {
			throw new EmployeeException(e.getMessage(), e);
		}
	}

	@Override
	public EmployeeResponse getSignupResponse(EmployeeSignup employeeSignup) throws EmployeeException {
		try {
			EmployeeE employeeE = new EmployeeE();
			BeanUtils.copyProperties(employeeSignup, employeeE);
			List<Address> addressList = new ArrayList<>();
			employeeSignup.addressList().forEach(addressModel -> {
				Address newAddress = new Address();
				BeanUtils.copyProperties(addressModel, newAddress);
				addressList.add(newAddress);
			});
			employeeE.setAddressList(addressList);
			employeeE.setManager(employeeE);
//            employeeE.setManager(employeeRepository.findById(employeeSignup.managerId()).orElseThrow());
			EmployeeE newEmployee = employeeRepository.save(employeeE);
			employeeE.getAddressList().forEach(address -> {
				address.setEmployee(newEmployee);
				addressRepository.save(address);
			});
			return EmployeeResponse.getInstance(newEmployee);
		} catch (NoSuchElementException e) {
			throw new EmployeeException(
					"No employee found with given id: " + employeeSignup.managerId() + " to allot as manager");
		} catch (BeansException e) {
			throw new EmployeeException(e.getMessage(), e);
		} catch (DataIntegrityViolationException e) {
			throw new EmployeeExistsException("Employee with email already exists: " + e.getMessage());
		}
	}

	@Override
	public EmployeeResponse getEmployeeProfile() throws EmployeeException {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String email = (String) authentication.getPrincipal();
		try {
			return EmployeeResponse.getInstance(employeeRepository.findByEmail(email).orElseThrow());
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("No employee found with email: " + email, e);
		} catch (DataIntegrityViolationException e) {
			throw new EmployeeException(e.getMessage(), e);
		}
	}

	@Override
	public EmployeeResponse getEmployeeById(String employeeId) throws EmployeeException {
		try {
			EmployeeE employeeE = employeeRepository.findById(employeeId).orElseThrow();
			return EmployeeResponse.getInstance(employeeE);
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Employee Not Found with Id: " + employeeId);
		} catch (DataAccessException e) {
			throw new EmployeeException("Database Error: " + e.getMessage());
		}
	}

	@Override
	public List<EmployeeResponse> getAllEmployees() throws EmployeeException {
		try {
			List<EmployeeE> employee = employeeRepository.findAll();
			log.debug("my list: " + employee.get(0).getAddressList());
			return employee.stream().map(EmployeeResponse::getInstance).collect(Collectors.toList());
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Employees Not Found");
		} catch (DataAccessException e) {
			throw new EmployeeException("Database Error: " + e.getMessage());
		}
	}

	@Override
	public EmployeeResponse updateEmployeeById(String employeeId, EmployeeUpdate employeeDetails)
			throws EmployeeException {
		try {
			EmployeeE employeeE = employeeRepository.findById(employeeId).orElseThrow();
			for (Address address : employeeE.getAddressList()) {
				addressRepository.deleteById(address.getId());
			}
			employeeE.setAddressList(null);
			BeanUtils.copyProperties(employeeDetails, employeeE);
			List<Address> addressList = new ArrayList<>();
			employeeDetails.addressList().forEach(addressModel -> {
				Address newAddress = new Address();
				BeanUtils.copyProperties(addressModel, newAddress);
				addressList.add(newAddress);
			});
			employeeE.setAddressList(addressList);
			employeeE.setManager(employeeE);
			employeeE.getAddressList().forEach(address -> {
				address.setEmployee(employeeE);
				addressRepository.save(address);
			});
			EmployeeE newEmployee = employeeRepository.save(employeeE);
			return EmployeeResponse.getInstance(newEmployee);
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Employee Not Found with Id: " + employeeId);
		} catch (BeansException e) {
			throw new EmployeeException(e.getMessage(), e);
		} catch (DataIntegrityViolationException e) {
			throw new EmployeeExistsException("Employee with email already exists: " + e.getMessage());
		}
	}

	@Override
	public Boolean deleteEmployeeById(String employeeId) throws EmployeeException {
		try {
			if (employeeRepository.findById(employeeId).get() != null) {
				employeeRepository.deleteById(employeeId);
				return true;
			}
			return false;
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Employee Not Found with Id: " + employeeId);
		} catch (DataAccessException e) {
			throw new EmployeeException("Database Error: " + e.getMessage());
		}
	}

	@Override
	public List<EmployeeResponse> getAllEmployeesByManagerId(String managerId) throws EmployeeException {
		try {
			List<EmployeeE> employeeList = employeeRepository.findByManagerId(managerId).orElseThrow();
			return employeeList.stream().map(EmployeeResponse::getInstance).collect(Collectors.toList());
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("Employees Not Found with ManagerId: " + managerId);
		} catch (DataAccessException e) {
			throw new EmployeeException("Database Error: " + e.getMessage());
		}

	}

	@Override
	public CurrentEmployeeDataResponse getCurrentEmployeeData() throws EmployeeException {
		Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
		String email = (String) authentication.getPrincipal();
		try {
			EmployeeE employee = employeeRepository.findByEmail(email).orElseThrow();
			List<EmployeeE> managedEmployeeList = employeeRepository.findByManagerId(employee.getId()).orElseThrow();
			return new CurrentEmployeeDataResponse(EmployeeResponse.getInstanceWithExpenseWithFiles(employee),
					managedEmployeeList.stream().map(EmployeeResponse::getInstanceWithExpenseWithFiles)
							.collect(Collectors.toList()));
		} catch (NoSuchElementException e) {
			throw new EmployeeNotFoundException("No employee found with email: " + email, e);
		}
	}

}
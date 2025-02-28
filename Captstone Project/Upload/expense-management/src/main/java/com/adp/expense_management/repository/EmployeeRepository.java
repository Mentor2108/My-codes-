package com.adp.expense_management.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.adp.expense_management.entity.EmployeeE;

@Repository
public interface EmployeeRepository extends JpaRepository<EmployeeE, String> {

	Optional<EmployeeE> findByEmail(String email);

	Optional<List<EmployeeE>> findByManagerId(String managerId);
}

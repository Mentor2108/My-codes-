package com.adp.expense_management.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.adp.expense_management.entity.ExpenseE;

@Repository
public interface ExpenseRepository extends JpaRepository<ExpenseE, String> {
		
}
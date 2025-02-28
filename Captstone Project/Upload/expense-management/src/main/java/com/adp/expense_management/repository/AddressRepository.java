package com.adp.expense_management.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.adp.expense_management.entity.Address;

@Repository
public interface AddressRepository extends JpaRepository<Address, String>{
	
}

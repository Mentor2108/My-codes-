package com.adp.expense_management;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

@SpringBootApplication
@EnableDiscoveryClient
public class ExpenseManagementApplication {

	public static void main(String[] args) {
		SpringApplication.run(ExpenseManagementApplication.class, args);
	}

}

package com.adp.auth.feign;

import com.adp.auth.model.EmployeeLoginRequest;
import com.adp.auth.model.EmployeeSignupRequest;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.Optional;

@FeignClient(name = "EXPENSE-MANAGEMENT", fallback = EmployeeFallback.class)
public interface EmployeeService {
    @PostMapping(value = "/api/employee/login")
    Optional<EmployeeLoginRequest> getLoginResponse(@RequestBody EmployeeLoginRequest employeeLoginRequest);

    @PostMapping(value = "/api/employee/signup")
    Object getSignupResponse(@RequestBody EmployeeSignupRequest employeeSignupRequest);
}

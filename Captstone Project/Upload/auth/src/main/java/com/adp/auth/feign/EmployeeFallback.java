package com.adp.auth.feign;

import com.adp.auth.model.EmployeeLoginRequest;
import com.adp.auth.model.EmployeeSignupRequest;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

import java.util.Map;
import java.util.Optional;

@Component
@Slf4j
public class EmployeeFallback implements EmployeeService {
    @Override
    public Optional<EmployeeLoginRequest> getLoginResponse(EmployeeLoginRequest employeeLoginRequest) {
        log.error("could not connect to server");
        return Optional.empty();
    }

    @Override
    public Object getSignupResponse(EmployeeSignupRequest employeeSignupRequest) {
        log.error("could not connect to server");
        return Map.of("error", "could not connect to server");
    }
}

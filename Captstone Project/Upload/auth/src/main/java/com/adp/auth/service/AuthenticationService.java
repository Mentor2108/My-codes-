package com.adp.auth.service;

import com.adp.auth.exception.AuthenticationException;
import com.adp.auth.model.EmployeeLoginRequest;
import com.adp.auth.model.EmployeeSignupRequest;
import com.adp.auth.model.LoginResponse;
import com.adp.auth.model.TokenValidationResponse;
import com.fasterxml.jackson.databind.node.ObjectNode;

public interface AuthenticationService {
    Object signup(EmployeeSignupRequest employee) throws AuthenticationException;
    LoginResponse login(EmployeeLoginRequest employee) throws AuthenticationException;
    TokenValidationResponse validateToken(String token) throws AuthenticationException;
}
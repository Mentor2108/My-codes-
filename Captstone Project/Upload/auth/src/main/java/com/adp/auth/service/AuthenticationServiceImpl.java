package com.adp.auth.service;

import com.adp.auth.exception.AuthenticationException;
import com.adp.auth.feign.EmployeeService;
import com.adp.auth.model.EmployeeLoginRequest;
import com.adp.auth.model.EmployeeSignupRequest;
import com.adp.auth.model.LoginResponse;
import com.adp.auth.model.TokenValidationResponse;
import io.jsonwebtoken.security.SignatureException;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.NoSuchElementException;

@Service
@RequiredArgsConstructor
@Slf4j
public class AuthenticationServiceImpl implements AuthenticationService {

    private final JwtService jwtService;
    private final EmployeeService employeeService;
    private final PasswordEncoder passwordEncoder;
    private final AuthenticationManager authenticationManager;
    private final UserDetailsService service;

    @Override
    public Object signup(EmployeeSignupRequest employee) {
        EmployeeSignupRequest employeeWithEncodedPassword = new EmployeeSignupRequest(employee.firstName(), employee.lastName(),
                employee.email(), passwordEncoder.encode(employee.password()), employee.dateOfBirth(), employee.addressList(),
                employee.gender(), employee.managerId());
        Object newObject = employeeService.getSignupResponse(employeeWithEncodedPassword);
        return newObject;
    }

    @Override
    public LoginResponse login(EmployeeLoginRequest employee) throws AuthenticationException {
        String email = employee.email();
        try {
            authenticationManager.authenticate(new UsernamePasswordAuthenticationToken(email, employee.password()));

            return new LoginResponse(jwtService.generateToken(employee), jwtService.getExpirationTime());
        } catch (org.springframework.security.core.AuthenticationException e) {
            throw new AuthenticationException(e.getMessage(), e);
        } catch (NoSuchElementException e) {
            throw new AuthenticationException("no user found with email: " + email, e);
        }
    }

    @Override
    public TokenValidationResponse validateToken(String token) throws AuthenticationException {
        try {
            String userName = jwtService.extractUsername(token);
            UserDetails userDetails = service.loadUserByUsername(userName);
            if (jwtService.validateToken(token, userDetails)) {
                return new TokenValidationResponse(true, userName, List.of("USER"));
//                return new TokenValidationResponse(true, jwtService.extractUsername(token), jwtService.getRolesFromToken(token));
            }
            return new TokenValidationResponse(false, null, null);
        } catch (org.springframework.security.core.AuthenticationException | SignatureException e) {
            throw new AuthenticationException(e.getMessage(), e);
        }
    }
}

package com.adp.auth.controller;

import com.adp.auth.model.TokenValidationResponse;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;

import com.adp.auth.exception.AuthenticationException;
import com.adp.auth.model.EmployeeLoginRequest;
import com.adp.auth.model.EmployeeSignupRequest;
import com.adp.auth.model.LoginResponse;
import com.adp.auth.service.AuthenticationService;
import com.fasterxml.jackson.databind.node.ObjectNode;

import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.validation.Valid;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

import java.util.Map;

//@Api
@RestController
@RequestMapping("/auth")
@RequiredArgsConstructor
@Slf4j
public class AuthController {

	private final AuthenticationService authenticationService;
//    private final JwtService jwtService;

	@PostMapping("/signup")
	public ResponseEntity<Object> signup(@Valid @RequestBody EmployeeSignupRequest employee, HttpServletResponse response,
										 HttpServletRequest request) {
		try {
			Object newEmployee = authenticationService.signup(employee);

//            String jwtToken = jwtService.generateToken(newEmployee.email());
//            Cookie cookie = new Cookie("Authorization", jwtToken);
//			cookie.setMaxAge(24 * 60 * 60); // 1 day
//			cookie.setHttpOnly(true);
//			cookie.setSecure(true);
//			cookie.setDomain("localhost");
//			cookie.setPath("/");
//			response.addCookie(cookie);

			log.info("a new employee is added");
			return ResponseEntity.ok(newEmployee);
		} catch (AuthenticationException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

	@PostMapping("/login")
	public ResponseEntity<LoginResponse> login(@Valid @RequestBody EmployeeLoginRequest employee,
			HttpServletResponse response) {
		try {
			LoginResponse loginResponse = authenticationService.login(employee);

			Cookie cookie = new Cookie("Authorization", loginResponse.token());
			cookie.setMaxAge(24 * 60 * 60); // 1 day
			cookie.setHttpOnly(true);
			cookie.setSecure(true);
			cookie.setDomain("localhost");
			cookie.setPath("/");
			response.addCookie(cookie);

			log.info("user with email " + employee.email() + " successfully logged in");
			return ResponseEntity.ok(loginResponse);
		} catch (AuthenticationException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}

    @GetMapping("/logout")
    public ResponseEntity<Map<String, String>> logout(HttpServletResponse response) {
        Cookie cookie = new Cookie("Authorization", null);
        cookie.setMaxAge(0); // Delete the cookie
        cookie.setHttpOnly(true);
        cookie.setSecure(true);
        cookie.setDomain("localhost");
        cookie.setPath("/");
        response.addCookie(cookie);

        return ResponseEntity.ok(Map.of("response", "User successfully logged out."));
    }

	@PostMapping("/validate/jwt")
	public ResponseEntity<TokenValidationResponse> validateToken(@Valid @RequestBody ObjectNode token) {
		try {
			TokenValidationResponse response = authenticationService.validateToken(token.get("token").asText());
			log.info("user successfully validated: " + response);
			return ResponseEntity.ok(response);
		} catch (AuthenticationException e) {
			log.error(e.getMessage());
			throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
		}
	}
}
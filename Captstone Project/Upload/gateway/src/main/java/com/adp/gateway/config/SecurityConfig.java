package com.adp.gateway.config;

import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.reactive.EnableWebFluxSecurity;
import org.springframework.security.config.web.server.ServerHttpSecurity;
import org.springframework.security.web.server.SecurityWebFilterChain;

@Configuration
@RequiredArgsConstructor
@EnableWebFluxSecurity
public class SecurityConfig {

    @Bean
    public SecurityWebFilterChain filterChain(ServerHttpSecurity http) throws Exception {
        return http.csrf(ServerHttpSecurity.CsrfSpec::disable)
//                .authorizeExchange(authorizeExchangeSpec -> authorizeExchangeSpec
//                        .pathMatchers("/auth/**").permitAll()
//                        .pathMatchers("/api/employee/login", "/api/employee/signup").permitAll()
//                        .anyExchange()
//                        .authenticated())
//                     .addFilterAt(jwtFilter, OrderedGatewayFilter)
                .build();
    }

}
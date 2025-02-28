package com.adp.gateway.service;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.core.ParameterizedTypeReference;
import org.springframework.stereotype.Service;
import org.springframework.web.reactive.function.client.WebClient;
import reactor.core.publisher.Mono;

import java.util.Map;

@Service
@RequiredArgsConstructor
@Slf4j
public class AuthService {
    private final WebClient.Builder webClient;
        private final ParameterizedTypeReference<Map<String, Object>> json = new ParameterizedTypeReference<>() {
    };

    public Mono<Map<String, Object>> validateToken(String token) {
        return webClient.build()
                .post()
                .uri("http://AUTH/auth/validate/jwt")
                .bodyValue(Map.of("token", token))
                .retrieve()
                .bodyToMono(json)
                .onErrorResume(exception -> {
                    log.error(exception.getMessage());
                    return Mono.just(Map.of("verified", false));
                });
    }
}

package com.adp.gateway.filter;

import com.adp.gateway.service.AuthService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.cloud.gateway.filter.GatewayFilter;
import org.springframework.cloud.gateway.filter.GatewayFilterChain;
import org.springframework.cloud.gateway.filter.factory.AbstractGatewayFilterFactory;
import org.springframework.http.HttpCookie;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;
import org.springframework.web.server.ServerWebExchange;
import reactor.core.publisher.Mono;

import java.util.List;
import java.util.Map;

@RefreshScope
@Component
@Slf4j
public class JwtFilterFactory extends AbstractGatewayFilterFactory<JwtFilterFactory.Config> {

    private final AuthService authService;

    public JwtFilterFactory(AuthService authService) {
        super(Config.class);
        this.authService = authService;
    }

    @Override
    public GatewayFilter apply(Config config) {
        return ((exchange, chain) -> {
            String token = extractJwtFromCookies(exchange, HttpHeaders.AUTHORIZATION);

            if (token == null) {
                log.error("no authorization token found in incoming request");
                exchange.getResponse().setStatusCode(HttpStatus.UNAUTHORIZED);
                return exchange.getResponse().setComplete();
            }

            return authService.validateToken(token)
                    .flatMap(map -> {
                        if (!(Boolean) map.get("verified")) {
                            exchange.getResponse().setStatusCode(HttpStatus.UNAUTHORIZED);
                            return exchange.getResponse().setComplete();
                        }

                        try {
                            exchange
                                    .getRequest()
                                    .mutate()
                                    .header("X-Authenticated-User", (String) map.get("username"))
                                    .header("X-User-Roles", String.join(",", (List<String>) map.get("roles")))
                                    .build();
                            return chain.filter(exchange);
                        } catch (ClassCastException e) {
                            log.error(e.getMessage());
                            exchange.getResponse().setStatusCode(HttpStatus.UNAUTHORIZED);
                            return exchange.getResponse().setComplete();
                        }
                    });
        });
    }

    private String extractJwtFromCookies(ServerWebExchange exchange, String cookieName) {
        HttpCookie cookie = exchange
                .getRequest()
                .getCookies()
                .getFirst(cookieName);
        return cookie != null ? cookie.getValue() : null;
    }

    public static class Config {
    }
}

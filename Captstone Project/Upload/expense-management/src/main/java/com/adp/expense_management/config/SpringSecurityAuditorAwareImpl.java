package com.adp.expense_management.config;

import lombok.RequiredArgsConstructor;
import org.springframework.data.domain.AuditorAware;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Component;

import java.util.Objects;
import java.util.Optional;

@Component
@RequiredArgsConstructor
public class SpringSecurityAuditorAwareImpl implements AuditorAware<String> {

    @Override
    public Optional<String> getCurrentAuditor() {
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        String auditor = "System";

        if (Objects.nonNull(authentication)) {
            auditor = authentication.getName();

            if (auditor.equals("anonymousUser")) {
                return Optional.of("System");
            }
        }
        return Optional.of(auditor);
    }
}
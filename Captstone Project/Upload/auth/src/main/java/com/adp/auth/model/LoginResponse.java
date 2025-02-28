package com.adp.auth.model;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

public record LoginResponse (
        String token,

        @JsonProperty("expires_in")
        long expiresIn){
}
package com.adp.auth.model;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonValue;

import java.util.stream.Stream;

@JsonIgnoreProperties(ignoreUnknown = true)
public enum Gender {
    MALE("MALE"),
    FEMALE("FEMALE"),
    NON_BINARY("NON-BINARY"),
    OTHER("OTHER");

    private String value;

    private Gender(String value) {
        this.value = value;
    }

    @JsonValue
    public String getValue() {
        return value.toUpperCase();
    }
}

package com.adp.auth.model;

import java.util.List;

//Need to take input of address in the end
public record TokenValidationResponse (

        Boolean verified,

        String username,

        List<String> roles) {
}
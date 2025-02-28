package com.adp.auth.constraints;

import com.adp.auth.model.Gender;
import org.springframework.core.convert.converter.Converter;
import org.springframework.stereotype.Component;

@Component
public class CaseInsensitiveGender implements Converter<String, Gender> {
    @Override
    public Gender convert(String source) {
        try {
            return Gender.valueOf(source.toUpperCase());
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Invalid value for enum: " + source);
        }
    }
}
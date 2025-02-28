package com.adp.expense_management.constraints;

import org.springframework.core.convert.converter.Converter;
import org.springframework.stereotype.Component;

import com.adp.expense_management.entity.Gender;

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
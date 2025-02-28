package com.adp.expense_management.entity;

import java.util.stream.Stream;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import com.fasterxml.jackson.annotation.JsonValue;

import jakarta.persistence.AttributeConverter;
import jakarta.persistence.Converter;

@JsonIgnoreProperties(ignoreUnknown = true)
public enum Gender {
	MALE("MALE"), FEMALE("FEMALE"), NON_BINARY("NON_BINARY"), OTHER("OTHER");

	private String value;

	private Gender(String value) {
		this.value = value;
	}

	@JsonValue
	public String getValue() {
		return value;
	}

	@Converter(autoApply = true)
	public static class GenderConverter implements AttributeConverter<Gender, String> {

		@Override
		public String convertToDatabaseColumn(Gender gender) {
			if (gender == null) {
				return null;
			}
			return gender.getValue().toUpperCase();
		}

		@Override
		public Gender convertToEntityAttribute(String value) {
			if (value == null) {
				return null;
			}

			return Stream.of(Gender.values()).filter(g -> g.getValue().equals(value.toUpperCase())).findFirst()
					.orElseThrow(IllegalArgumentException::new);
		}
	}
}

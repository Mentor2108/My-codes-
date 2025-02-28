package com.adp.expense_management.model;

import com.fasterxml.jackson.annotation.JsonProperty;

public record AddressRequest(

		@JsonProperty("address_type")
		String addressType,

		@JsonProperty("line_one")
		String lineOne,

		@JsonProperty("line_two")
		String lineTwo,

		String street,

		String city,

		String state,

		String country,

		@JsonProperty("postal_code") String postalCode) {

}

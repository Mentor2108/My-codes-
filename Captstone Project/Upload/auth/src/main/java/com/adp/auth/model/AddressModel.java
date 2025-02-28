package com.adp.auth.model;

import com.fasterxml.jackson.annotation.JsonProperty;

public record AddressModel(
        @JsonProperty(access = JsonProperty.Access.WRITE_ONLY)
        String id,

        @JsonProperty("address_type") String addressType,

        @JsonProperty("line_one") String lineOne,

        @JsonProperty("line_two") String lineTwo,

        String street,

        String city,

        String state,

        String country,

        @JsonProperty("postal_code") String postalCode) {
}

package com.adp.expense_management.model;

import com.adp.expense_management.entity.*;
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

    public static AddressModel getInstance(Address address) {
        return new AddressModel(
                address.getId(),
                address.getAddressType(),
                address.getLineOne(),
                address.getLineTwo(),
                address.getStreet(),
                address.getCity(),
                address.getState(),
                address.getCountry(),
                address.getPostalCode());
    }
}

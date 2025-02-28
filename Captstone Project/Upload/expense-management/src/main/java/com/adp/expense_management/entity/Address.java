package com.adp.expense_management.entity;

import com.fasterxml.jackson.annotation.JsonProperty;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Entity
@Table(name = "batch2_team1_capstone_entity_address")
@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Address extends AuditBase {
    @Id
    @GeneratedValue(strategy = GenerationType.UUID)
    @JsonProperty(access = JsonProperty.Access.WRITE_ONLY)
    private String id;

    @Column(nullable = false)
    @JsonProperty("address_type")
    private String addressType;

    @Column(nullable = false)
    @JsonProperty("line_one")
    private String lineOne;

    @JsonProperty("line_two")
    private String lineTwo;

    private String street;

    @Column(nullable = false)
    private String city;

    @Column(nullable = false)
    private String state;

    @Column(nullable = false)
    private String country;

    @Column(nullable = false)
    @JsonProperty("postal_code")
    private String postalCode;

    @ManyToOne(cascade = {CascadeType.MERGE, CascadeType.PERSIST, CascadeType.REFRESH})
    @JsonProperty(access = JsonProperty.Access.READ_ONLY)
    private EmployeeE employee;
}

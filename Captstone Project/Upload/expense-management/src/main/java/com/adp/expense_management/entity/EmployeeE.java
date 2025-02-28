package com.adp.expense_management.entity;

import java.time.LocalDate;
import java.util.List;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Entity
@Table(name = "batch2_team1_capstone_entity_employee")
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class EmployeeE extends AuditBase {
	@Id
	@GeneratedValue(strategy = GenerationType.UUID)
	private String id;

	@Column(nullable = false)
	private String firstName;

	private String lastName;

	@Column(nullable = false, unique = true)
	private String email;

	@Column(nullable = false)
	private String password;

	@Column(nullable = false)
	private LocalDate dateOfBirth;

	@OneToMany(mappedBy = "employee")
	@JsonProperty("address")
	private List<Address> addressList;

	@Column(nullable = false)
	@Convert(converter = Gender.GenderConverter.class)
	private Gender gender;

	@JoinColumn(foreignKey = @ForeignKey(ConstraintMode.NO_CONSTRAINT))
	@ManyToOne(cascade = CascadeType.ALL)
	private EmployeeE manager;

	@OneToMany(mappedBy = "employee")
	private List<ExpenseE> expenseList;
}

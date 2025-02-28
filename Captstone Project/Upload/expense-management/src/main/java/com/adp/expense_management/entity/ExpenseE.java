package com.adp.expense_management.entity;

import java.time.LocalDate;
import java.util.List;

import com.adp.expense_management.model.FileResponse;
import com.fasterxml.jackson.annotation.JsonIgnore;

import jakarta.persistence.*;
import lombok.*;

@Entity
@Table(name = "batch2_team1_capstone_entity_expense")
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class ExpenseE extends AuditBase {
	@Id
	@GeneratedValue(strategy = GenerationType.UUID)
	private String id;

	@Column(nullable = false)
	@Enumerated(EnumType.STRING)
	private ExpenseType expenseType;

	@Column(nullable = false)
	private LocalDate dateOfExpense;

	private String fromLocation;

	private String toLocation;

	private TravelType travelType;

	@Column(nullable = false)
	private Float amount;

    @ManyToOne(cascade = {CascadeType.MERGE, CascadeType.PERSIST, CascadeType.REFRESH})
    private EmployeeE employee;

    @OneToMany(mappedBy = "expense")
    private List<FileRecord> fileList;

    private String additionalComments;

	@Column(nullable = false)
	@JsonIgnore
	@Enumerated(EnumType.STRING)
	private ExpenseStatus expenseStatus;

	private String remarks;
}

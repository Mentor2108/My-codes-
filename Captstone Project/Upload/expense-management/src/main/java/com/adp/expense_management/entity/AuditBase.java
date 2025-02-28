package com.adp.expense_management.entity;

import java.time.LocalDateTime;

import org.springframework.data.annotation.CreatedBy;
import org.springframework.data.annotation.CreatedDate;
import org.springframework.data.annotation.LastModifiedBy;
import org.springframework.data.annotation.LastModifiedDate;
import org.springframework.data.jpa.domain.support.AuditingEntityListener;

import com.fasterxml.jackson.annotation.JsonIgnore;

import jakarta.persistence.Column;
import jakarta.persistence.EntityListeners;
import jakarta.persistence.MappedSuperclass;
import jakarta.persistence.Temporal;
import jakarta.persistence.TemporalType;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.experimental.SuperBuilder;

@Getter
@NoArgsConstructor
@MappedSuperclass
@EntityListeners(AuditingEntityListener.class)
@SuperBuilder
public class AuditBase {
    @CreatedBy
    @Column(updatable = false)
    @JsonIgnore
    private String createdBy;

    @CreatedDate
    @Column(updatable = false)
    @Temporal(TemporalType.TIMESTAMP)
    @JsonIgnore
    private LocalDateTime createdOn;

    @LastModifiedBy
    @JsonIgnore
    private String updatedBy;

    @LastModifiedDate
    @Temporal(TemporalType.TIMESTAMP)
    @JsonIgnore
    private LocalDateTime updatedOn;
}

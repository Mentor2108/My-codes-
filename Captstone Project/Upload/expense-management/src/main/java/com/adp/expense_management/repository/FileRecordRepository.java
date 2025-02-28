package com.adp.expense_management.repository;

import com.adp.expense_management.entity.FileRecord;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface FileRecordRepository extends JpaRepository<FileRecord, String> {

}
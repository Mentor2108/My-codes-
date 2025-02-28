package com.adp.expense_management.service;

import com.adp.expense_management.entity.FileRecord;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.model.FileResponse;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

public interface FileService {
    List<FileResponse> saveFile(String expenseId, List<MultipartFile> files) throws FileRecordException, IOException;

    byte[] retrieveFile(String expenseId, String fileId) throws FileRecordException, IOException;

    ExpenseResponse getAllFilesMetadataByExpenseId(String expenseId) throws ExpenseException;

    FileResponse getFileMetaDataById(String fileId) throws FileRecordException;
}

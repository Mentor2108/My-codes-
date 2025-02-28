package com.adp.expense_management.service;

import com.adp.expense_management.entity.ExpenseE;
import com.adp.expense_management.entity.FileRecord;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.ExpenseNotFoundException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.model.FileResponse;
import com.adp.expense_management.repository.ExpenseRepository;
import com.adp.expense_management.repository.FileRecordRepository;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

@Service
@Slf4j
public class FileServiceImpl implements FileService {

    private static final String UPLOAD_DIR = "static" + File.separator + "uploaded";

    @Autowired
    private FileRecordRepository fileRepository;
    @Autowired
    private ExpenseRepository expenseRepository;

    @Override
    public List<FileResponse> saveFile(String expenseId, List<MultipartFile> files) throws FileRecordException, IOException {
        try {
            ExpenseE expense = expenseRepository.findById(expenseId).orElseThrow();
            if (files == null) {
                throw new FileRecordException("No files found in request");
            }

            List<FileResponse> fileResponse = new ArrayList<>();
            for (MultipartFile file : files) {
                String fileName = "uploaded-file-" + System.currentTimeMillis();
                Path directoryPath = Paths.get(UPLOAD_DIR + File.separator + expense.getId());
                directoryPath = Files.createDirectories(directoryPath);

                Path filePath = Paths.get(directoryPath + File.separator + fileName);
                Files.write(filePath, file.getBytes());
                log.debug("file {} saved in directory: {}", file.getOriginalFilename(), directoryPath);

                FileRecord fileRecord = new FileRecord();
                fileRecord.setFileName(file.getOriginalFilename());
                fileRecord.setFilePath(filePath.toString());
                fileRecord.setFileSize(file.getSize());
                fileRecord.setFileType(file.getContentType());
                fileRecord.setExpense(expense);

                fileRecord = fileRepository.save(fileRecord);
                fileResponse.add(FileResponse.getInstance(fileRecord));
            }
            return fileResponse;
        } catch (NoSuchElementException e) {
            throw new FileRecordException("No expense found with id: " + expenseId, e);
        }
    }

    @Override
    public byte[] retrieveFile(String expenseId, String fileId) throws FileRecordException, IOException {
        try {
            FileRecord fileRecord = fileRepository.findById(fileId).orElseThrow();

            if (!fileRecord.getExpense().getId().equals(expenseId)) {
                throw new FileRecordException("No file found with id: " + fileId + " corresponding to expense: " + expenseId);
            }

            Path filePath = Paths.get(fileRecord.getFilePath());
            return Files.readAllBytes(filePath);
        } catch (NoSuchElementException e) {
            throw new FileRecordException("No file found with id: " + fileId, e);
        }
    }

    @Override
    public ExpenseResponse getAllFilesMetadataByExpenseId(String expenseId) throws ExpenseException {
        try {
            ExpenseE expense = expenseRepository.findById(expenseId).orElseThrow();
            return ExpenseResponse.getInstanceWithFile(expense);
        } catch (NoSuchElementException e) {
            throw new ExpenseNotFoundException("No expense found with id: " + expenseId);
//        } catch (DataAccessException e) {
//            throw new ExpenseException("Database Error: " + e.getMessage());
        }
    }

    @Override
    public FileResponse getFileMetaDataById(String fileId) throws FileRecordException {
        return FileResponse.getInstance(
                fileRepository
                        .findById(fileId)
                        .orElseThrow(() -> new FileRecordException("No file found with id: " + fileId)));
    }
}

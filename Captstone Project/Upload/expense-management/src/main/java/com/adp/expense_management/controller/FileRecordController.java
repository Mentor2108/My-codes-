package com.adp.expense_management.controller;

import com.adp.expense_management.entity.FileRecord;
import com.adp.expense_management.exception.ExpenseException;
import com.adp.expense_management.exception.FileRecordException;
import com.adp.expense_management.model.ExpenseResponse;
import com.adp.expense_management.model.FileResponse;
import com.adp.expense_management.service.FileService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.server.ResponseStatusException;

import java.io.IOException;
import java.util.List;

@RestController
@RequestMapping("/api/expense")
@RequiredArgsConstructor
@Slf4j
public class FileRecordController {
    private final FileService fileService;

    @GetMapping("/expense-id/{expense_id}/file/list")
    public ResponseEntity<ExpenseResponse> getAllFilesMetadataByExpenseId(@PathVariable("expense_id") String expenseId) {
        try {
            ExpenseResponse expenseResponse = fileService.getAllFilesMetadataByExpenseId(expenseId);
            return ResponseEntity.ok(expenseResponse);
        } catch (ExpenseException e) {
            log.error(e.getMessage());
            throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
        }
    }

    @PostMapping("/expense-id/{expense_id}/upload")
    public ResponseEntity<List<FileResponse>> uploadFile(@PathVariable("expense_id") String expenseId, @RequestParam("file") List<MultipartFile> files) {
        try {
            List<FileResponse> savedFiles = fileService.saveFile(expenseId, files);
            return ResponseEntity.ok(savedFiles);
        } catch (FileRecordException e) {
            log.error(e.getMessage());
            throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
        } catch (IOException e) {
            log.error(e.getMessage());
            throw new ResponseStatusException(HttpStatus.INTERNAL_SERVER_ERROR, e.getMessage());
        }
    }

    @GetMapping("/expense-id/{expense_id}/download/file-id/{file_id}")
    public ResponseEntity<byte[]> downloadFile(@PathVariable("expense_id") String expenseId, @PathVariable("file_id") String fileId) {
        try {
            byte[] fileData = fileService.retrieveFile(expenseId, fileId);
            FileResponse fileResponse = fileService.getFileMetaDataById(fileId);

            HttpHeaders headers = new HttpHeaders();
            headers.add(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename\"" + fileResponse.fileName() + "\"");
            headers.add(HttpHeaders.CONTENT_TYPE, fileResponse.fileType());
            return new ResponseEntity<>(fileData, headers, HttpStatus.OK);
        } catch (FileRecordException e) {
            log.error(e.getMessage());
            throw new ResponseStatusException(HttpStatus.BAD_REQUEST, e.getMessage());
        } catch (IOException e) {
            log.error(e.getMessage());
            throw new ResponseStatusException(HttpStatus.INTERNAL_SERVER_ERROR, e.getMessage());
        }
    }
}

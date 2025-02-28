package com.adp.expense_management.model;

import com.adp.expense_management.entity.FileRecord;
import com.fasterxml.jackson.annotation.JsonProperty;

public record FileResponse(
        String id,

        @JsonProperty("file_name") String fileName,

        @JsonProperty("file_path") String filePath,

        @JsonProperty("file_size") Long fileSize,

        @JsonProperty("file_type") String fileType) {
    public static FileResponse getInstance(FileRecord file) {
        return new FileResponse(
                file.getId(),
                file.getFileName(),
                file.getFilePath(),
                file.getFileSize(),
                file.getFileType());
    }
}

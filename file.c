#include <stdio.h>
#include <stdlib.h>

#include "file.h"


FILE* open_file(char path[]) {
    FILE* f = fopen(path, "r");
    
    if (f == NULL) {
        fprintf(stderr, "Failed to open file: %s \n", path);
        exit(EXIT_FAILURE);
    } else {
        return f;
    }
}

//Returns the length of the file
int file_length(FILE* f) {
    //save the current position
    int current_position = ftell(f);
    
    //seek to the end of the file and save the position
    fseek(f, 0, SEEK_END);
    int end_of_file = ftell(f);
    
    //go back to the position we started at
    fseek(f, current_position, SEEK_SET);
    
    return end_of_file;
}

char* read_file(FILE* f) {
    int buffer_size = (file_length(f) + 1) * sizeof(char);
    char* buffer = (char*)malloc(buffer_size);
    
    size_t end = fread(buffer, sizeof(char), buffer_size, f);
    
    if (ferror(f) != 0) {
        fprintf(stderr, "Failed to read file!\n");
        exit(EXIT_FAILURE);
    }else {
        buffer[end+1] = '\0';
    }
    
    return buffer;
}
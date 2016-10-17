#include "file.h"

#include <stdio.h>
#include <stdlib.h>

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
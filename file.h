#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_H
#define FILE_H

FILE* open_file(char path[]);
int file_length(FILE* f);
char* read_file(FILE* f);

#endif /* FILE_H */


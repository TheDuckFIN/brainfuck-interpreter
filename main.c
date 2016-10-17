#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "brainfuck.h"

int main(int argc, char** argv) {
    
    FILE* f = open_file("programs/bottles.b");
    
    char* program = read_file(f);
    
    run(program);
    
    //printf("Length: %d\n", file_length(f));
    //printf("Content: %s\n", program);
    
    return EXIT_SUCCESS;
}


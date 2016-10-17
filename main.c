#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "brainfuck.h"

int main(int argc, char** argv) {
    
    if (argc != 2) {
        printf("Usage: brainfuck <file>\n");
    }else {
        FILE* f = open_file(argv[1]);
    
        char* program = read_file(f);

        run(program);
    }
    
    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "file.h"

int main(int argc, char** argv) {
    
    stack_init();
    
    FILE* f = open_file("programs/helloworld.b");
    
    int program_length = file_length(f);
    
    char* program = (char*)malloc(program_length * sizeof(char));
    
    
    printf("Length: %d\n", file_length(f));
    
    /*for(int i = 0; i < 10; i++) {
        stack_push((i + 1) * 2);
    }
    
    while(!stack_isEmpty()) 
        printf("Num: %d \n", stack_pop());
    */
     
    stack_destruct();
    
    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>

#include "brainfuck.h"
#include "stack.h"

int MEMORY_SIZE = 100;
char* memory;
char* pointer;

void init() {
    memory = (char*)calloc(MEMORY_SIZE, sizeof(char));
    
    if (memory == NULL) {
        fprintf(stderr, "Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    
    pointer = memory;
}

void destruct() {
    free(memory);
}

void run(char* program) {
    init();
    stack_init();
    
    //which character we're currently at
    int cpointer = 0;
    
    while(program[cpointer] != '\0') {
        char c = program[cpointer];
        
        switch(c) {
            
            case '+':
                (*pointer)++;
                break;
                
            case '-':
                (*pointer)--;
                break;
            
            case '>':
                pointer++;
                break;
                
            case '<':
                pointer--;
                
            case '.':
                putchar(*pointer);
                break;
                
            case '[':
                stack_push(cpointer);
                
                if (*pointer == 0) {
                    while(!stack_isEmpty()) {
                        cpointer++;
                        if (program[cpointer] == '[') stack_push(cpointer);
                        if (program[cpointer] == ']') stack_pop();
                    }
                }
                
                break;
                
            case ']':
                if (*pointer == 0) {
                    stack_pop();
                }else {
                    cpointer = stack_peek();
                }
               
                break;
                
            default:
                break;
                
        }
        
        cpointer++;
    }
    
    stack_destruct();
    destruct();
}


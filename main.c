#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv) {
    
    stack_init();
    
    for(int i = 0; i < 1000; i++) {
        stack_push((i + 1) * 2);
    }
    
    while(!stack_isEmpty()) 
        printf("Num: %d \n", stack_pop());
    
    stack_destruct();
    
    return EXIT_SUCCESS;
}


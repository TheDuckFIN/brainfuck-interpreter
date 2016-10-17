#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

int INITIAL_SIZE = 10;
int *stack;
int top = -1;

//Initializes the stack by allocating memory
void stack_init() {
    stack = (int*)malloc(INITIAL_SIZE * sizeof(int));
    
    if (stack == NULL) {
        fprintf(stderr, "Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
}

//pushes a number to the top of the stack
void stack_push(int number) {
    top++;
    stack[top] = number;
}

//removes the number from the top of the stack and returns it
int stack_pop() {
    if (!stack_isEmpty()) {
        int ret = stack[top];
        top--;
        return ret;
    }
}

int stack_isEmpty() {
    return top == -1;
}

//Free the memory allocated to the stack
void stack_destruct() {
    free(stack);
}
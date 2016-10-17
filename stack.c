#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
 *
 * Dynamic stack implementation
 *
 */

//initial stack size
int INITIAL_SIZE = 10;

int current_size;
int *stack;
int top = -1;

//Initializes the stack by allocating memory
void stack_init() {
    stack = (int*)malloc(INITIAL_SIZE * sizeof(int));
    current_size = INITIAL_SIZE;
    
    if (stack == NULL) {
        fprintf(stderr, "Failed to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
}

//pushes a number to the top of the stack
void stack_push(int number) {
    //allocate more memory if there's no more space
    if ((current_size - 1) <= top) {
        current_size = current_size * 2;
        
        stack = (int*)realloc(stack, current_size * sizeof(int));
    }
    
    top++;
    stack[top] = number;
}

//removes the number from the top of the stack and returns it
int stack_pop() {
    if (!stack_isEmpty()) {
        int ret = stack[top];
        top--;
        return ret;
    }else {
        fprintf(stderr, "Could not pop from stack because it's empty!\n");
    }
}

//returns the number from the top of the stack
int stack_peek() {
    if (!stack_isEmpty()) {
        return stack[top];
    }else {
        fprintf(stderr, "Could not peek from stack because it's empty!\n");
    }
}

int stack_isEmpty() {
    return top == -1;
}

//Free the memory allocated to the stack
void stack_destruct() {
    free(stack);
}
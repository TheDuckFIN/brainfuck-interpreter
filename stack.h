#ifndef STACK_H
#define STACK_H

void stack_init();
void stack_destruct();

void stack_push(int number);
int stack_pop();
int stack_peek();
int stack_isEmpty();

#endif /* STACK_H */


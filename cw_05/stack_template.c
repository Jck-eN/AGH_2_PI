#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

/*****************************
* implements functions below *
*****************************/

void push(stack* s, int n) {
    
}

int pop(stack* s) {
    
}

bool is_empty(stack* s) {
    
}

stack* new_stack(int size) {
    
}

void delete_stack(stack* s) {
    
}

int main() {
    int size;
    scanf("%d", &size);
    stack* s = new_stack(size);
    int tmp;

    /***************************************
    * read values and push them on stack   *
    * pop values from stack and print them *
    ***************************************/

    delete_stack(s);
}
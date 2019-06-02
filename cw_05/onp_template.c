#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

/***************************************
* paste here your stack implementation *
***************************************/

typedef enum entry_type {number, add, subtract, multiply, divide} entry_type;

entry_type parse(char* raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}

/****************************
* implement functions below *
****************************/

void do_add(stack* s) {
    
}

void do_subtract(stack* s) {

}

void do_multiply(stack* s) {

}

void do_divide(stack* s) {

}

int read_and_calculate(int operands_count, int max_entry_size) {
    stack* operands = new_stack(operands_count);
    char* entry = malloc((max_entry_size+1)*sizeof(char));
    while(/* ??? */) {
        for(int i=0; i<max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);
        // put your code here
    }


    delete_stack(operands);
    free(entry);
    return result;
}

int main() {
    int operands_count, max_entry_size;
    scanf("%d", &operands_count);
    scanf("%d", &max_entry_size);
    printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}
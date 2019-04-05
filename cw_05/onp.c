#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

int to_int(char* string){
    int sign=1;
    int offset=0;
    if(string[0]=='-'){
        sign=-1;
        offset=1;
    }
    int res=0;
    for(int i=0; string[i+offset]!='\0'; i++){
        res=10*res+string[i+offset]-'0';
    }
    res*=sign;
    return res;
}

void push(stack* s, int n) {
    if(s->top+1<s->max_size){
        s->top++;
        s->elements[s->top]=n;
    }
    return;
}

bool is_empty(stack* s) {
    if(s->top<0) return true;
    else return false; 
}

int pop(stack* s) {
    if(is_empty(s)==false){
        int res=s->elements[s->top];
        s->top--;
        return res;
    }
    return -1;
}

stack* new_stack(int size) {
    stack* s = malloc(sizeof(stack));
    if(size>0) s->elements = malloc(size*sizeof(int));
    s->top = -1;
    s->max_size=size;
    return s;
}

void delete_stack(stack* s) {
    free(s->elements);
    free(s);
    return;
}

typedef enum entry_type {number, add, subtract, multiply, divide} entry_type;

entry_type parse(char* raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}

void do_add(stack* s) {
    int x = pop(s);
    int y = pop(s);
    push(s, x+y);
}

void do_subtract(stack* s) {
    int x = pop(s);
    int y = pop(s);
    push(s, y-x);
}

void do_multiply(stack* s) {
    int x = pop(s);
    int y = pop(s);
    push(s, x*y);
}

void do_divide(stack* s) {
    int x = pop(s);
    int y = pop(s);
    push(s, y/x);
}

int read_and_calculate(int operands_count, int max_entry_size) {
    stack* operands = new_stack(operands_count);
    char* entry = malloc((max_entry_size+1)*sizeof(char));
    int numbers=0;
    while(numbers<operands_count || operands->top>0) {
        for(int i=0; i<max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);
        if(parse(entry)==number) {
            push(operands, to_int(entry));
            numbers++;
        }
        else{
            switch (parse(entry))
            {
                case add:
                    do_add(operands);
                    break;
                case subtract:
                    do_subtract(operands);
                    break;
                case multiply:
                    do_multiply(operands);
                    break;
                case divide:
                    do_divide(operands);
                    break;
            }
        }
    }
    int result = pop(operands);
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
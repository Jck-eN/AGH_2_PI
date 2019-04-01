#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

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

int main() {
    int size;
    scanf("%d", &size);
    stack* s = new_stack(size);
    for(int i=0; i<size; i++)
    {
        int val;
        scanf("%d", &val);
        push(s, val);
    }
    for(int i=0; i<size; i++){
        printf("%d\n", pop(s));
    }

    delete_stack(s);
}
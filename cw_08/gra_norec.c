#include<stdio.h>
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


int count_routes(int** board, int N, int from_x, int from_y, int to_x, int to_y) {
    
    if(from_x>=N || from_y>=N || from_x>to_x || from_y>to_y || *(*(board+from_y)+from_x)==0) return 0;
    if(from_x==to_x && from_y == to_y) return 1;
    int result=0;
    int x, y;
    stack* s = new_stack(10*N*N);
    push(s, from_x);    
    push(s, from_x);
    while(!is_empty(s)){
        y = pop(s);
        x = pop(s);
        if(!(x>=N || y>=N || x>to_x || y>to_y || *(*(board+y)+x)==0)){
            if(x==to_x && y==to_y) result+=1;
            else{
                push(s, x+1); 
                push(s, y+1); 

                push(s, x+1); 
                push(s, y); 

                push(s, x); 
                push(s, y+1); 
            }
        }
    }
    delete_stack(s);
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    int** board = malloc(N*sizeof(int*));
    for (int i=0; i<N; i++) {
        board[i] = malloc(N*sizeof(int));
        for (int j=0; j<N; j++) scanf("%d", &board[i][j]);
    }

    int from_x, from_y, to_x, to_y;
    scanf("%d", &from_x);
    scanf("%d", &from_y);
    scanf("%d", &to_x);
    scanf("%d", &to_y);
    printf("%d\n", count_routes(board, N, from_x, from_y, to_x, to_y));

    for(int i=0; i<N; i++) free(board[i]);
    free(board);
}
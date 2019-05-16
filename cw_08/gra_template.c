#include<stdio.h>
#include <stdlib.h>

int count_routes(int** board, int N, int from_x, int from_y, int to_x, int to_y) {
    /*********************
    * put your code here *
    *********************/
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
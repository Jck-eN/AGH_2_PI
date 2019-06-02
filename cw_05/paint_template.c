#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point {
    int x, y;
} point;

typedef struct queue {
    int start, end, size;
    point **elements;
} queue;

/****************************
* implement functions below *
****************************/

queue *new_queue(int size) {
    
}

void delete_queue(queue *q) {
    
}

void put(queue *q, point *value) {
    
}

point *get(queue *q) {
    
}

bool is_empty(queue *q) {
    
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    // put first point
    while (!is_empty(points)) {
        // add your code here
    }
    delete_queue(points);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int **image = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        image[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int x, y, color;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &color);
        fill(image, n, x, y, color);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);
}
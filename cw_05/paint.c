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

queue *new_queue(int size) {
    queue* q = malloc(sizeof(queue));
    q->elements=malloc(size*sizeof(point*));
    q->start=0;
    q->end=0;
    q->size=size;
    return q;
}

bool is_empty(queue *q) {
    if(q->start==q->end) return true;
    else return false;
}


void delete_queue(queue *q) {
    for(int i=0; i<q->size; i++){
 //       free(q->elements[i]);
    }
    free(q->elements);
    free(q);
}

void put(queue *q, point *value) {
    q->elements[q->end]=value;
    if(q->end+1<q->size){
        q->end++;
    }
    else{
        q->end=0;
    }
}

point *get(queue *q) {
    if(is_empty(q)==true) return NULL;
    point* tmp = q->elements[q->start];
    q->elements[q->start]=NULL;
    q->start++;
    if(q->start>=q->size){
        q->start=0;
    }
    return tmp;
}

void fill(int **image, int n, int x, int y, int color) {
    queue *points = new_queue(n * n);
    point* p=malloc(sizeof(point));
    p->x=x;
    p->y=y;
    put(points, p);

    while (!is_empty(points)) {
        p = get(points);
        int t_x=p->x;
        int t_y=p->y;
        image[t_x][t_y]=color;
        free(p);
        if(t_y+1<n && image[t_x][t_y+1] == 0){
            p=malloc(sizeof(point));
            p->x=t_x;
            p->y=t_y+1;
            put(points, p);
            p=NULL;
        }
        if(t_y-1>=0 && image[t_x][t_y-1] == 0){
            p=malloc(sizeof(point));
            p->x=t_x;
            p->y=t_y-1;
            put(points, p);
            p=NULL;
        }
        if(t_x+1<n && image[t_x+1][t_y] == 0){
            p=malloc(sizeof(point));
            p->x=t_x+1;
            p->y=t_y;
            put(points, p);
            p=NULL;
        }
        if(t_x-1>=0 && image[t_x-1][t_y] == 0){
            p=malloc(sizeof(point));
            p->x=t_x-1;
            p->y=t_y;
            put(points, p);
            p=NULL;
        }
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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {
    for(int i=1; i<n; i++){
        for(int j=n-i; j<n; j++){
            if(*(*(tab+i)+j)!=0) return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int** tab;
    tab = malloc(n*sizeof(int*));
    for(int i=0; i<n; i++){
        tab[i] = malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            scanf("%d", (*(tab+i)+j));
        }
    }

    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");

    for(int i; i<n; i++){
        free(*(tab+i));
    }
    free(tab);
}
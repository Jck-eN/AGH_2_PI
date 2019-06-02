#include <stdio.h>
#include <stdlib.h>

int find_divider(int* tab, int n) {

   /***********************
    *  put your code here  * 
    ***********************/

}

int main() {
    int n;
    scanf("%d", &n);
    int* tab = malloc(n * sizeof(int));
    for (int i=0; i<n; i++) {
        scanf("%d", &tab[i]);
    }
    printf("%d\n", find_divider(tab, n));
    free(tab);
}
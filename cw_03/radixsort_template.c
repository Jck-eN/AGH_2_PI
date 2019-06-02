#include<stdio.h>
#include<stdlib.h>

int digit(char* number, int position) {
    return (int)(number[position] - '0');
}

void sortByPosition(char** tab, int n, int pos) {
    int k = 10;
    int *counters = malloc(k*sizeof(int));
    char** result = malloc(n*sizeof(char*));
    /***********************
    * Place your code here *
    ***********************/
}

void radixSort(char** tab, int n, int length) {
    /***********************
    * Place your code here *
    ***********************/
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {

		int n, length;
		scanf("%d", &n);
        scanf("%d", &length);
		char **tab = malloc(n*sizeof(char*));
		for(int i=0; i<n; i++) {
			tab[i] = malloc((length+1)*sizeof(char));
            int read_len = scanf("%s", tab[i]);
		}

        radixSort(tab, n, length);
        for(int i=0; i<n; i++) {
            printf("%s\n", tab[i]);
            free(tab[i]);
        }
        free(tab);
    }
}

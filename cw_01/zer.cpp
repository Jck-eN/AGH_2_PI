#include <stdio.h>

int n;

int* my_first_sort(int tab[]) {
    
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1; j++){
            if(tab[j]>tab[j+1]){
                int tmp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=tab[j];
            }
        }
    }
    
    return tab;    
}

int main() {
    
    scanf("%d", &n);

    int *tab = NULL;
    tab = new int[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);     
    }
    
    int *res = my_first_sort(tab);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);     
    }

    delete[] tab;    
}

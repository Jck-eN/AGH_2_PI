#include <stdio.h>
#include <stdlib.h>

int find_divider(int* tab, int n) {
  int sum=0;
  int sum_l=tab[0];
  for(int i=0; i<n; i++)
    {
      sum+=tab[i];
      
    }
  for(int j=1; j<n; j++)
    {
      if(sum_l*2+tab[j]==sum) return j;
      sum_l+=tab[j];
      
    }
  
  
  return -1;
  
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

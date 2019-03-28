#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int n){
    if(n==2 || n==3) return true;

    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

bool non_decreasing(int n){
    int num=9;
    while(n>0){
        if(n%10>num) return false;
        num=n%10;
        n/=10;
    }
    return true;
}

int main()
{
    struct timeval start, end;
    int n;
    scanf("%d", &n);
    
   for(int i=2; i<n; i++){
        if(non_decreasing(i) && is_prime(i)) printf("%d\n", i);
    }

}

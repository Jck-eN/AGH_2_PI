#include <stdio.h>
#include <stdlib.h>

void encrypt(char* message, int n) {
    
    /***********************
    *  put your code here  * 
    ***********************/
    
}

int main() {
    int n;
    scanf("%d", &n);
    char* message = (char*) malloc((n+1) * sizeof(char));
    fgets(message, n+1, stdin); // reads \n
    fgets(message, n+1, stdin);
    encrypt(message, n);
    printf("%s\n", message);
    free(message);
}
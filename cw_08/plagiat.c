#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;

int minimum(int a, int b, int c){
    if(a<b){
        if(a<c) return a;
        else return c;
    }
    else{
        if(b<c) return b;
        else return c;
    }
}


int distance(char* a, int a_length, char* b, int b_length) {
    int** d = malloc((a_length+1)*sizeof(int*));
    for(int i=0; i<=a_length; i++){
        d[i]=malloc((b_length+1)*sizeof(int));
    }

    for(int i=0; i<=a_length; i++){
        d[i][0]=i;
    }    
    for(int i=1; i<=b_length; i++){
        d[0][i]=i;
    }
    int cost=-1;
    for(int i=1; i<=a_length; i++){
        for(int j=1; j<=b_length; j++){
            if(a[i-1]==b[j-1]) cost=0;
            else cost=1;
            d[i][j]=minimum(
                d[i-1][j]+1,    //usuwanie
                d[i][j-1]+1,    //wstawianie
                d[i-1][j-1]+cost);  //zamiana
        }
    }
    int res= d[a_length][b_length];
    for(int i=0; i<=a_length; i++){
        free(d[i]);
    }
    free(d);
    return res;
}

int main() {
    char* a = malloc(MAX_TEXT_LENGTH*sizeof(char));
    char* b = malloc(MAX_TEXT_LENGTH*sizeof(char));
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;

int distance(char* a, int a_length, char* b, int b_length) {
    /*********************
    * put your code here *
    *********************/
}

int main() {
    char* a = malloc(MAX_TEXT_LENGTH*sizeof(char));
    char* b = malloc(MAX_TEXT_LENGTH*sizeof(char));
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}
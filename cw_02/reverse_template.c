#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} node;

node* reverse(node* list) {
 
    /***********************
    *  put your code here  * 
    ***********************/
 
}

int main() {
    int n;
    int val;
    scanf("%d", &n);
    node* list = malloc(sizeof(node));
    list->next = NULL;
    node* tmp = list;
    for (int i=0; i<n; i++) {
        scanf("%d", &val);
        tmp->next = malloc(sizeof(node));
        tmp = tmp->next;
        tmp->value = val;
        tmp->next = NULL;
    }
    tmp = list->next;
    free(list);
    
    list = reverse(tmp);

    while(list != NULL) {
        printf("%d\n", list->value);
        /****************************
        * remember - remove garbage *
        ****************************/
    }
}
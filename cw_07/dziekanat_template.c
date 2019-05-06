#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) {
    /*********************
    * put your code here *
    * *******************/
}

void delete_tree(node* root) {
    /*********************
    * put your code here *
    * *******************/
}

node* insert (node* root, node* to_insert) {
    /*********************
    * put your code here *
    * *******************/
   return root;
}

node* find (node* root, int number) {
    /*********************
    * put your code here *
    * *******************/
}

node* delete(node* root, int number) {
    /*********************
    * put your code here *
    * *******************/
   return root;
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }

    while (r-- > 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}

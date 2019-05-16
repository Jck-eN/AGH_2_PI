#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {
    /*********************
    * put your code here *
    * *******************/
}

void delete_tree(node* root) {
    /*********************
    * put your code here *
    * *******************/
}

void insert (node* root, node* to_insert) {
    /*********************
    * put your code here *
    * *******************/
}

void print_in_order(node* root) {
    /*********************
    * put your code here *
    * *******************/
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int val;

    if (n-- > 0) {
        scanf("%d", &val);
        root = create_node(val);
    }
    while (n-- > 0) {
        scanf("%d", &val);
        insert(root, create_node(val));
    }

    print_in_order(root);

    delete_tree(root);
}

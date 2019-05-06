#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {
    node* p = malloc(sizeof(node));
    p->left=p->right=p->parent=NULL;
    p->value = val;
    return p;
}

void delete_tree(node* root) {
    if(root==NULL)return;
    if(root->left!=NULL) delete_tree(root->left);
    if(root->right!=NULL) delete_tree(root->right);
    free(root);
}

void insert (node* root, node* to_insert) {
    if(root==NULL){
        root=to_insert;
        return;
    } 
    if(to_insert->value<root->value){
        if(root->left!=NULL){
            insert(root->left, to_insert);
        }
        else{
            root->left=to_insert;
            to_insert->parent=root;
        }
    }
    else{
        if(root->right!=NULL){
            insert(root->right, to_insert);
        }
        else{
            root->right=to_insert;
            to_insert->parent=root;
        }
    }
}

void print_in_order(node* root) {
    if(root==NULL) return;
    if(root->left!=NULL) print_in_order(root->left);
    printf("%d\n", root->value);
    if(root->right!=NULL) print_in_order(root->right);
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

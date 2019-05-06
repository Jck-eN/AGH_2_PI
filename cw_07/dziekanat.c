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
    node* p = malloc(sizeof(node));
    p->left=p->right=p->parent=NULL;
    p->number = number;
    p->name = malloc(MAX_NAME_SIZE*sizeof(char));
    strcpy(p->name, name);
    return p;
}

void delete_tree(node* root) {
    if(root==NULL) return;
    if(root->left!=NULL) delete_tree(root->left);
    if(root->right!=NULL) delete_tree(root->right);
    free(root->name);
    free(root);
}

node* insert (node* root, node* to_insert) {
    if(root==NULL){
        root=to_insert;
        return root;
    } 
    if(to_insert->number<root->number){
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
    return root;
}

node* find (node* root, int number) {
    if(root==NULL) return root;
    if(root->number==number) return root;
    else if(root->number<number) return find(root->left, number);
    else return find(root->right, number);
}

node* delete(node* root, int number) {
    if(root==NULL) return root;
    if(number<root->number) root->left=delete(root->left, number);
    else if(number>root->number) root->right=delete(root->right, number);
    else{
        if(root->left==NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        node* nast = root->right;
        while(nast!=NULL && nast->left!=NULL) nast=nast->left;
        root->number=nast->number;
        strcpy(root->name,nast->name);
        root->right=delete(root->right, nast->number);
    }
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

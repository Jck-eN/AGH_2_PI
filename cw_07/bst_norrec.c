#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {

    node *x = (node*)malloc(sizeof(node));
    x->left = x->right = x->parent = NULL;
    x->value = val;
    return x;
}

void delete_tree(node* root) {

    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);

    free(root);
}

void insert (node* root, node* to_insert) {

    int x = to_insert->value;
    node *q = root;
    while (1)
    {
        if (q->value <= x && q->right == NULL)
        {
            q->right = to_insert;
            to_insert->parent = q;
            return;
        }
        else if (q->value > x && q->left == NULL)
        {
            q->left = to_insert;
            to_insert->parent = q;
            return;
        }
        else if (q->value <= x)
            q = q->right;
        else
            q = q->left;
    }
}

node *nexter(node *x)
{
    node *p=x;
    node *q=x;
    if (x->right != NULL)
    {
        q = x->right;
        while (q->left != NULL) q = q->left;
        return q;
    }
    else
    {
        p = x;
        q = x->parent;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->parent;
        }
        return q;
    }

}

void print_in_order(node* root) {

    node *p = root;
    while (p->left != NULL)
        p = p->left;

    while (p != NULL)
    {
        printf("%d", p->value);
        printf("\n");
        p = nexter(p);
    }
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

/*
5
3
2
4
1
5
*/

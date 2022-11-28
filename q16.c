// Write non-recursive programs for Inorder, Preorder and postorder traversals
#include<stdio.h>

struct node{
    int data;
    struct node *left, *right;
};
struct node *root;


void preorder(){
    struct node *current = root;
    printf("%d ", current->data);
    while(current->left);
}


struct node* newNode(int data){
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void main(){
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    preorder();
    inorder();
    postorder();
}
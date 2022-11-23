// implement stack using linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;


void push(int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    head = newnode;
}


void pop(){
    if(head!=NULL){
        struct node *temp = head;
        printf("\n%d", temp->data);
        // free(temp);
        head = head->next;
    }else{
        printf("\nstack underflow");
    }
}



int main(){
    while(1){
        printf("\n\nchoose operation\n1. push\n2. pop\n99. exit\n=>");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element: ");
            int element;
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
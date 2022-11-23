// Implement stack using linkedlist
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

void push(int element){
    struct node *current = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    if (current!=NULL){
        while (current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }else{
        head = newnode;
    }
}

void pop(){
    if (head==NULL){
        printf("stack underflow");
    }else{
        struct node *current = head;
        while (current->next!=NULL){
            current = current->next;
        }
        printf("%d", current->next->data);
        free(current->next);
        current=NULL;
    }
}

void view_stack(){
    struct node *current = head;
    current = current->next;
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    // printf("%d ", current->data);
}

int main(){
    while(1){
        printf("\n\nchoose operation\n1. push\n2. pop\n3. view stack\n4. exit\n\t=>");
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
        case 3:
            view_stack();
            break;
        case 4:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
// Write a program to reverse the linked list
/*
pop elements from the last of the original linkedlist and add to starting of new linkedlist
now swap the heads
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *private_head;

void push(int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    head = newnode;
}

void view(){
    struct node *current = head;
    while (current!=NULL){
        printf("%d", current->data);
        current = current->next;
    }
}

struct node* push_private_ll(int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = private_head;
    private_head = newnode;
}

void reverse(){
    while(head!=NULL){
        struct node *temp = head;
        push_private_ll(temp->data);
        head = head->next;
    }
    head = private_head;
    printf("\nreversed\n");
}

int main(){
    while(1){
        printf("\n\nchoose operation\n1. push at begin\n2. view\n3. reverse\n99. exit\n=>");
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
            view();
            break;
        case 3:
            reverse();
            break;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
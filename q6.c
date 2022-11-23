// Write a program for finding the middle node in the single liked list
/*
logic
    1. traverse through the linkedlist and find the total number of nodes
    2. travel n/2 number of nodes from head to attain the middle node
*/
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



void find_middle_element(){
    if (head==NULL){
        printf("linkedlist is empty!\n");
    }else{
        struct node *current = head;
        int count = 0;
        while (current!=NULL){
            current = current->next;
            count++;
        }
        // printf("\n\n => numbe of ele = %d", count);
        current = head;
        for(int i = 0;i<count/2;i++){
            current = current->next;
        }
        printf("\n\nmiddle element = %d\n", current->data);
    }
}


int main(){
    while(1){
        printf("\n\nchoose operation\n1. push\n2. find middle element\n99. exit\n=>");
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
            find_middle_element();
            return 0;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
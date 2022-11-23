// Write a program for finding a loop in the linked list
/*
doing a double loop though the linkedlist and checking if an memory address comes again
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
    newnode->next = NULL;
    if (head==NULL){
        head = newnode;
    }else{
        struct node *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void pop(){
    struct node *current = head;
    struct node *temp;
    if (current!=NULL){
        while(current->next!=NULL){
            temp = current;
            current = current->next;
        }
        temp->next = NULL;
        printf("%d", current->data);
        free(current);
    }
}

int check_loop(){
    struct node *current1 = head;
    while (current1->next->next!=NULL){
        struct node *current2 = current1->next;
        while (current2->next!=NULL){
            if (current1==current2){
                printf("Loop exists");
                return 0;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    printf("no loop");
    return 0;
    
}

int main(){
    while(1){
        printf("\n\nchoose operation\n1. push\n2. pop\n3. check for loops\n99. exit\n=>");
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
            check_loop();
            break;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
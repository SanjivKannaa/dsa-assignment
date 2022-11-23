// impolement queue using linkedlist

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;


void enqueue(int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    head = newnode;
}

void dequeue(){
    if(head!=NULL){
        struct node *current = head;
        if (head->next==NULL){
            printf("\n%d", head->data);
            head = NULL;
        }else{
            while(current->next->next!=NULL){
                current = current->next;
            }
            printf("\n%d", current->next->data);
            current->next = NULL;
        }
    }else{
        printf("queue empty");
    }
}

int main(){
    while(1){
        printf("\n\nchoose operation\n1. enqueue\n2. dequeue\n99. exit\n=>");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element: ");
            int element;
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
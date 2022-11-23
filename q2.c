// impolement queue using linkedlist

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;


void enqueue(int element){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    if (head==NULL){
        head = newnode;
    }else{
        struct node *current = head;
        while(current!=NULL){
            current = current->next;
        }
    }
}
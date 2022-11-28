// Write a program to find the intersection point of two single linked lists
/*
maintain 2 loops through the linkedlists and find if any address or data matches
*/
#include<stdio.h>
#include<stdlib.h>



struct node {
	int data;
	struct node* next;
};


struct node *head1=NULL;
struct node *head2=NULL;


struct node* getintersection(struct node* head1, struct node* head2){
	while (head2){
		struct node* temp = head1;
		while (temp){
			if (temp == head2)
				return head2;
			temp = temp->next;
		}
		head2 = head2->next;
	}
	return NULL;
}

int main(){
    struct node* newNode;
    struct node* head1 = (struct node*)malloc(sizeof(struct node));
    head1->data = 10;
    struct node* head2 = (struct node*)malloc(sizeof(struct node));
    head2->data = 3;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 6;
    head2->next = newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    struct node* intersectionPoint = getintersection(head1, head2);
    if (!intersectionPoint)
        printf(" No Intersection Point \n");
    else
        printf("Intersection Point: %d\n", intersectionPoint->data);
}
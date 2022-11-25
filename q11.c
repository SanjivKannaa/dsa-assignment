// Write a program to find the intersection point of two single linked lists
/*
maintain 2 loops through the linkedlists and find if any address or data matches
*/
#include<stdio.h>
#include<stdlib.h>




struct node{
    int data;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;



void insert_last(struct node *root, int element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;
    struct node *current = root;
    if(current!=NULL){
        while (current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }else{
        root=newnode;
    }
}


void delete_last(struct node *root){
    struct node *current = root;
    struct node *temp;
    if (current!=NULL){
        while(current->next!=NULL){
            temp = current;
            current = current->next;
        }
        temp->next = NULL;
        printf("%d ", current->data);
        free(current);
    }
}



void check(){
    struct node *current1 = head1;
    struct node *current2 = head2;
    while(current1!=NULL){
        while(current2!=NULL){
            if (current1->data == current2->data){
                printf("Intersection at value : %d", current1->data);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}


int main(){
    while(1){
        printf("\n\nchoose operation\n1. inert to LL 1\n2. remove from LL 1\n3. push to LL 2\n4. pop to lL 2\n5. check for intersection\n99. exit\n=>");
        int choice, element;
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("enter the element: ");
            scanf("%d", &element);
            insert_last(head1, element);
            break;
        case 2:
            delete_last(head1);
            break;
        case 3:
            printf("enter the element: ");
            scanf("%d", &element);
            insert_last(head2, element);
            break;
        case 4:
            delete_last(head2);
            break;
        case 5:
            check();
            break;
        case 99:
            return 0;
        default:
            printf("invalid option");
        }
    }
}
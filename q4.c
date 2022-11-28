// implementation of queue using stack
#include <stdio.h>
#include <stdlib.h>
  
int stack1[100], stack2[100];
int top1 = -1, top2 = -1;
int count = 0;


void push1(int data){
    stack1[++top1] = data;
}
 
int pop1(){
    return(stack1[top1--]);
}
 
void push2(int data){
    stack2[++top2] = data;
}
 
int pop2(){
    return(stack2[top2--]);
}

void enqueue(){
    int data, i;
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}
 

void dequeue(){
    int i;
    for (i = 0;i <= count;i++){
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++){
        push1(pop2());
    }
}
 

void display(){
    int i;
    for (i = 0;i <= top1;i++){
        printf(" %d ", stack1[i]);
    }
}


void main(){
    int option;
    while (1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display queue\n99. exit");
        printf("\nEnter choice");
        scanf("%d", &option);
        switch (option){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 99:
                exit(0);
            default:
                printf("invalid option");
        }
    }
}
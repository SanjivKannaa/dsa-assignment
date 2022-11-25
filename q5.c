// Write a program for how stacks can be used for checking balancing of symbols
/*
valid symbols => (), [], {}
logic
    1. have a stack of type char
    2. go through the input string.
    3. if char is either of (, [, {
        put into stack
    4. if char is either of ), ], }
        pop from stack and cross verify for pair
            if correct pair
                pass
            else
                incorrect balancing
            if stack empty
                incorrect balancing
    5. after input string is over
        if stack is empty
            correct balancing
        else
            incorrect balancing
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *next;
};
struct node *head = NULL;


void push(char element){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = head;
    head = newnode;
}


char pop(){
    char data = head->data;
    head = head->next;
    return data;
}

char get_pair(char inp){
    if (inp=='('){return ')';}
    if (inp=='['){return ']';}
    if (inp=='{'){return '}';}
    if (inp==')'){return '(';}
    if (inp==']'){return '[';}
    if (inp=='}'){return '{';}
}

int main(){
    printf("enter the input string: ");
    char input_string[4];
    gets(input_string);
    for(int i=0;i<4;i++){
        if (input_string[i] == '\0'){
            break;
        }
        if (input_string[i]=='(' || input_string[i]=='[' || input_string[i]=='{'){
            push(input_string[i]);
        }
        if (input_string[i]==')' || input_string[i]==']' || input_string[i]=='}'){
            if(head==NULL){printf("symbols unbalanced");return 0;}
            char pop_value = pop();
            if (pop_value!=get_pair(input_string[i])){
                printf("symbols unbalanced %c", input_string[i]);
                return 0;
            }
        }
    }
    if (head==NULL){
        printf("symbols balanced");
    }else{
        printf("symbols unbalanced");
    }
    return 0;
}
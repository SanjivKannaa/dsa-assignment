// Write a program (Insertion and Deletion operations) to construct a hash table with linear probing technique

#include <stdio.h>
#define N 5
int s[N]; 
int IsFull(){
    int c=0;
    for(int i=0; i<N; i++){
        if (s[i]!=0){
            c++;
        }
    }
    if (c==N){
        return 1;
    }
    else{
        return 0;
    }
}


int IsEmpty(){
    int c=0;
    for(int i=0; i<N; i++){
        if (s[i]==0){
            c++;
        }
    }
    if (c==N){
        return 1;
    }
    else{
        return 0;
    }
}


void Insert(int a){
    if(IsFull()){
        printf("Hash Table is Full\n");
        return;
    }
    else{
        int hashkey,tmp=0;
        hashkey=a%N;
        if (s[hashkey]){
            for (int j=1; j<=N; j++){
                tmp=(hashkey+j)%N;
                if(!s[tmp]){
                    s[tmp]=a;
                    break;
                }
            }
        }
        else{
            s[hashkey]=a;
        }
    }
}


int Search(int x){
    int hashkey=x%N;
    if (s[hashkey]==x){
        return hashkey;
    }
    else{
        int i=1,end=0;
        while(end==0){
            hashkey=(hashkey+1)%N;
            i++;
            if(s[hashkey]==x){
                return hashkey;
            }
            if (i>=N){
                break;
            }
        }
        return -1;
    }
}
void Delete(int x){
    if (IsEmpty()){
        printf("Hash Table is Empty\n");
        return;
    }
    else{
        int tkey=Search(x);
        if (tkey!=-1){
            s[tkey]=0;
            return;
        }
        else{
            printf("Element not present in Hash Table\n");
            return;
        }
    }
}


void main(){
    int Exit=0;
    while(Exit==0){
        printf("1 to exit\n");
        printf("2 to insert\n");
        printf("3 to search\n");
        printf("4 to delete\n");
        int choice;
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1){
            Exit=1;
            continue;
        }
        else if (choice==2){
            int data;
            printf("Enter element:");
            scanf("%d",&data);
            Insert(data);
            continue;
        }
        else if (choice==3){
            int data;
            printf("Enter element:");
            scanf("%d",&data);
            int SRes=Search(data);
            if (SRes!=-1){
                printf("%d Found\n",data);
                continue;
            }
            else{
                printf("%d Not Found\n",data);
                continue;
            }
        }
        else if (choice==4){
            int data;
            printf("Enter element:");
            scanf("%d",&data);
            Delete(data);
            continue;
        }
        else{
            printf("Incorrect choice\n");
            continue;
        }
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define EmptyStack INT_MIN

typedef struct node{
    int data;
    struct node *next;
}Node;



Node *Push(Node *st,int data){
    Node *newnode = (Node* )malloc(sizeof(Node));
    if(newnode==NULL) return false;
    newnode->data = data;
    newnode->next = st;
    st = newnode;
    return st;
}

bool IsEmpty(Node *st){
    if(st == NULL) 
    {
        printf("Empty!\n");
        return true;
    }
    else
    {
        //printf("not empty!\n");
        return false;
    }
}



int Pop(Node **st){
    Node *temp; 
    temp = &(**st);
    int result; 

    if(IsEmpty(temp)) {
        printf("the stack is empty!\n");
        return INT_MIN;
    }else
    {
        int result = temp->data;
        *st=(*st)->next;
        free(temp);
        return result;
    }
}

void PrintStack(Node *st){
    int result ;
    while(!IsEmpty(st))
    {
        printf("Pop : %d\n",Pop(&st));
    }
}

int main(){
    Node *st = NULL;
    st = Push(st,1);
    st = Push(st,2); 
    st = Push(st,3);
    st = Push(st,4);
    PrintStack(st);    
   


}

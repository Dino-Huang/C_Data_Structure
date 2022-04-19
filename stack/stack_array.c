#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
int count = 0;

typedef struct stack{
    int items[MAX];
    int top;
}Stack;

void createEmptyStack(Stack *st){
    st->top = -1;
}

//check if stack is full
bool IsFull(Stack *st){
    if(st->top == MAX-1){
        return true;
    }else{
        return false;
    }
}

//check if stack is empty
bool IsEmpty(Stack *st){
    if(st->top == -1){
        return true;
    }else{
        return false;
    }
}

//Remove element from Stack.It decreases top by 1
void pop(Stack *st){
    if(IsEmpty(st)){
       printf("stack is empty!\n");
    }else{
        printf("Item popped : %d",st->items[st->top]);
        st->top--;
        count--;
    }
}

//Add element into stack is empty
void push(Stack *st, int item){
    if(IsFull(st)){
        printf("stack is full!\n");
    }else{
        st->top++;
        st->items[st->top] = item;
        printf("Item pushed : %d",st->items[st->top]);
        count++;
    }
}

//print elements of stack 
void PrintStack(Stack *st){
    if(IsEmpty(st)){
        printf("stack is empty!\n");
    }else{
        printf("Stack:\n");
        for (size_t i = 0; i < count; i++)
        {
            printf("%d ",st->items[i]);
        }
        printf("\n");
    }
}

int main(){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    createEmptyStack(st);

    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    printf("\nOriginal stack\n");
    PrintStack(st);
    pop(st);
    printf("\nAfter popping out\n");
    PrintStack(st);
}
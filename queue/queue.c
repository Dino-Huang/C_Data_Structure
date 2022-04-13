#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct queue{
    char item[MAX];
    int front;
    int rear;
}Queue;

void CreateEmptyQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

bool IsEmpty(Queue *q){
    if(q->rear == -1 && q->front ==-1 )
     return true;
    else
    return false;
}

bool IsFull(Queue *q){
    if(q->rear == (MAX -1))
    {
        return true;
    }
    else
        return false;
}

void EnQueue(Queue *q,char c){
    if(IsFull(q)){
        printf("Queue is Full!\n");
    }
    else{
        q->front=0;
        q->rear++;
        q->item[q->rear]= c;
        printf("%c is added!\n",c);
    }

}

void DeQueue(Queue *q){
    if(IsEmpty(q)){
        printf("Queue is Empty!\n");
    }
    else{
        printf("%c is deleted!\n",q->item[q->front]);
        q->item[q->front]='\0';//clear content
        q->front++;
        if(q->front>q->rear)
        {
            q->front =-1;
            q->rear =-1;
        }
    }
}

void PrintQueue(Queue *q){
    if(!IsEmpty(q))
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("item[%d] : %c\n",i,q->item[i]);
        }   
    }
}

int main(){
    Queue q;
    CreateEmptyQueue(&q);
    EnQueue(&q,'a');
    EnQueue(&q,'c');
    EnQueue(&q,'b');
    EnQueue(&q,'d');
    PrintQueue(&q);
    DeQueue(&q);
    EnQueue(&q,'a');
    EnQueue(&q,'c');
    EnQueue(&q,'b');
    EnQueue(&q,'d');
    EnQueue(&q,'a');
    EnQueue(&q,'c');
    EnQueue(&q,'b');
    EnQueue(&q,'d');
    PrintQueue(&q);

}
#include<stdio.h>
#include<stdlib.h>

typedef struct q_node{
    int data;
    struct q_node *next;
}Q_Node;

typedef struct queue{
    Q_Node *front,*rear;
}Queue;

Q_Node *newnode(int data){
    Q_Node *node = (Q_Node *)malloc(sizeof(Q_Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Queue *createqueue(){
    Queue *new_queue =(Queue *)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

Queue *EnQueue(Queue *queue,int data){
    // create a new node
    Q_Node *qnode = newnode(data);

    // If queue is empty, then new node is front and rear both
    if(queue->rear == NULL){
        queue->front = queue->rear = qnode;
        return queue;
    }

    // Add the new node at the end of queue and change rear
    queue->rear->next = qnode;
    queue->rear = qnode;
    
    return queue;
}

Queue *DeQueue(Queue *queue){
    if(queue->front == NULL)
    {
        printf("Queue is empty!\n");
        return queue;
    }

    //Delete the front node and change the front
    printf("Delete front node : %d\n",queue->front->data);
    // Store previous front and move front one node ahead
    Q_Node *temp= queue->front;
    queue->front = queue->front->next;

    // If front becomes NULL, then change rear also as NULL
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    // release memory
    free(temp);
    return queue;
}

void PrintQueue(Queue *q){
    if(q->rear == NULL)
    {
        printf("Queue is empty!\n");
    }else{
        Q_Node *temp = q->front;
        while(temp != NULL)
        {
            printf("Q[%d]->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    Queue *q = createqueue();
    q = EnQueue(q,1);
    q = EnQueue(q,2);
    q = EnQueue(q,3);
    q = EnQueue(q,4);
    PrintQueue(q);
    q = DeQueue(q);
    printf("After DeQueue : \n");
    PrintQueue(q);
    printf("Queue front : %d\n",q->front->data);
    printf("Queue rear : %d\n",q->rear->data);
    return 0;
}


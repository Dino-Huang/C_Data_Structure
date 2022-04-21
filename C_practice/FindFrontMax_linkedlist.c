#include<stdio.h>
#include<stdlib.h>
/*
1.給你一個linkedlist的head，但不知道多長，
請你找到前半段的最大值

ex: 2->1->3->4->5->1 output: 3

*/

typedef struct list_node{
    int Data;
    struct list_node* next ; 
}Linkedlist;

void FindFrontMax(Linkedlist* head){
    //count number of nodes in list
    int n = 0;
    Linkedlist* temp = head;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    printf("There is(are) %d nodes in linkedlist\n",n);
    temp = head;// re link temp to head

    n = n/2;// if 7 nodes, n = 3
    int Max = temp->Data;// data of first node
    for (int i = 1; i <= n; i++)
    {
        //assgin it to temp_v if data > temp_v
        if(temp->Data > Max)
        {
            Max = temp->Data;
        }
        // go to next node
        temp = temp->next;
    }
    printf("Maximum in the front part of Linkedlist is %d !\n",Max);
    
    //release memory
    free(temp);
}

int main(){

    //create linkedlist
    Linkedlist* head, *one, *two, *three, *four, *five, *six, *seven;

    //Allocate memory
    head = (Linkedlist*)malloc(sizeof(Linkedlist));
    one  = (Linkedlist*)malloc(sizeof(Linkedlist));
    two  = (Linkedlist*)malloc(sizeof(Linkedlist));
    three = (Linkedlist*)malloc(sizeof(Linkedlist));
    four = (Linkedlist*)malloc(sizeof(Linkedlist));
    five = (Linkedlist*)malloc(sizeof(Linkedlist));
    six = (Linkedlist*)malloc(sizeof(Linkedlist));
    seven = (Linkedlist*)malloc(sizeof(Linkedlist));

    //set data
    one->Data = 2;
    two->Data = 1;
    three->Data = 3;
    four->Data = 4;
    five->Data = 5;
    six->Data = 1;
    seven->Data = 4;

    //Node linked
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = NULL;

    //link head to one
    head = one ;
    

    //print out Linkedlist
    Linkedlist* copy = head;
    while(copy!=NULL)
    {
        printf("%d->",copy->Data);
        copy = copy->next;
    }
    printf("Null\n");//print Null at the end
    free(copy);

    FindFrontMax(head);
    
    return 0;
}
//linked list operations in c
//1. Insert node at front
//2. Insert node at end
//3. Insert node at specific position
//4. Delete node with key
//5. Search node
//6. Sort the linked list
//7. Display the linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct list_node{
    int data;
    struct list_node *next;
}Llist_node;

Llist_node *InsertAtFront(Llist_node *list, int data){
    if (list==NULL)
    {
        Llist_node *node;
        node = (Llist_node*)malloc(sizeof(Llist_node));
        node->data = data;
        node->next = NULL;
        return node;
    }
    Llist_node *node;
    node = (Llist_node*)malloc(sizeof(Llist_node));
    node->data = data;
    node->next = list;
    return node;
}  

Llist_node *InsertAtEnd(Llist_node *list, int data){
    
    Llist_node *node;
    node = (Llist_node*)malloc(sizeof(Llist_node));
    node->data = data;
    node->next = NULL;
    
    if(list == NULL)
    {
        list = node;
        return list;
    }
     Llist_node *p = list;//copy list to p
    while(p->next != NULL){p=p->next;}//find the last node
    p->next=node;//link to node to the end
    return list;
}

Llist_node *InsertAfterNode(Llist_node *list,int position, int data){
    int Llist_len = 1;
    Llist_node *temp = list;
    Llist_node *node;
    node = (Llist_node*)malloc(sizeof(Llist_node));
    node->data = data;
    node->next = NULL;
    //if Llist is empty then insert at front
    if(list == NULL ){
        list = InsertAtFront(list,data);
        return list;
    }
    //calculate Llist length
    while(temp->next!=NULL){
        temp=temp->next;
        Llist_len++;
    }
    //printf("Llist length : %d\n",Llist_len);


    //if insert position in the range 
    Llist_node *prev;
    temp = list;
    if (position > 0 && position < Llist_len)
    {
        for (size_t i = 0; i < position; i++)
        {
            prev = temp;
            temp=temp->next;
        }
        node->next = prev->next;
        prev->next = node;
        return list;
    }else
    {
        printf("Llist position is out of range!\n");
        return list;
    }
}

Llist_node *DeleteNode(Llist_node *list,int key){
    Llist_node *temp = list,*prev;

    if(temp==NULL){
        return list;
    }

    if(temp!=NULL&&temp->data==key){
        prev = temp->next;
        free(temp);
        list = prev;
        return list;
    }

    while(temp!=NULL&&temp->data!=key)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    free(prev);
    return list;
}

int *SearchNode(Llist_node *list,int key){
    Llist_node *temp=list;
    int count=1;

    if(temp == NULL){
        printf("List is empty!\n");
        return 0;
    }
    while(temp!=NULL && temp->data != key)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Llist_node *SortLlist(Llist_node *list){
    Llist_node *head = list,*nextptr;
    int temp ;

    if(head == NULL){
        return NULL;
    }else{
        while(head!=NULL){
            //traverse to the last node
            nextptr = head->next;
            while (nextptr!=NULL)
            {
                if(nextptr->data>head->data)
                {
                    temp = head->data;
                    head->data = nextptr->data;
                    nextptr->data = temp;
                }
                nextptr=nextptr->next;
            }
            head = head->next;
        }
        return list;
    }


}

Llist_node *Display_list(Llist_node *list){
    while (list!=NULL){
        printf("%d -> ",list->data);
        list=list->next;
    }
    printf("NULL\n");
    return list;
}

int main(){
    //initialize nodes
    Llist_node *head = NULL;
    head = InsertAtFront(head, 5);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 2);
    head = InsertAtEnd(head, 1);
    head = InsertAfterNode(head,2, 5);
    Display_list(head);
    head = DeleteNode(head,5);
    Display_list(head);
    int *index = SearchNode(head,1);
    printf("The node is found at position %d\n",index);
    head=SortLlist(head);
    Display_list(head);
    
    return 0;
}
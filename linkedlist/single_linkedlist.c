#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
    int data ;
    struct list_node *next;
}Linked_list;

Linked_list *new_node(int data){
    Linked_list *node=NULL;
    //dynamic memory allocation
    node=(Linked_list *)malloc(sizeof(Linked_list));
    //memory is not enough
    if(node == NULL) return NULL;

    node->data=data;
    node->next=NULL;

    return node;
}

Linked_list *push_node(Linked_list *list,int data){
    Linked_list *node=new_node(data);
    if (list == NULL){
        list = node;//if list is empty, then link a new node
    }else{
        Linked_list *p = list;//copy list to p
        while(p->next != NULL){p=p->next;}//find the last node
        p->next=node;//link to node to the end
    }
    return list;
}

Linked_list *delete_node(Linked_list *list,int key){
    Linked_list *temp = list,*prev;

    if (temp != NULL && temp->data==key)
    {
        list=temp->next;
        free(temp);
        return list;
    }
    while( temp->data!=key){
        prev = temp;//store previous ptr
        temp=temp->next;// point to next ptr
    }
    prev->next=temp->next;
    free(temp);
    free(prev);
    return list;
}

int display_list(Linked_list *list){
    printf("display list : \n");
    Linked_list *p = list;
    if(list == NULL) return NULL;
    while(p != NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 1;
}

int main(){
    Linked_list *list;
    list = push_node(list,1);
    list = push_node(list,2);
    list = push_node(list,3);
    list = push_node(list,4);
    list = push_node(list,5);
    
    display_list(list);
    //list=delete_node(list,1);
    list=delete_node(list,2);
    display_list(list);
    return 0;
}
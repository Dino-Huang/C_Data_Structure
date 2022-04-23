#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Linkedlist;

Linkedlist *InsertNode(Linkedlist *head, int data)
{
    Linkedlist *NewNode ;
    NewNode = (Linkedlist *) malloc(sizeof(Linkedlist));
    NewNode->data = data;
    NewNode->next = NULL;

    if (head==NULL)
    {
        head = NewNode;
        return head;
    }

    Linkedlist *temp = head; ;
    //head os not empty
    while(temp->next!= NULL)
    {
        //head move forward
        temp = temp->next;
    }
    temp->next= NewNode;
    
    return head;
}

Linkedlist *RemoveNode(Linkedlist *head,int data)
{
    Linkedlist *cur = head;
    Linkedlist *prev;

    if(cur==NULL) return cur;
    while(cur->data!=data)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);

    return head;
}

Linkedlist *ReverseLlist(Linkedlist*head)
{
    Linkedlist *cur = head;
    Linkedlist *prev = NULL, *next;

    while (cur!=NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur =next;
    }
    

    return prev;
}

void Swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

Linkedlist *BubbleSortLlist(Linkedlist *head){
  Linkedlist *cur = head;
  Linkedlist *index ;
  int temp;

  if (cur== NULL)
  {
      printf("It's empty list!\n");
      return cur;
  }
  while (cur != NULL)
  {
      index = cur->next;
      while (index != NULL)
      {
          if(index->data < cur->data )
          {
              temp = cur->data;
              cur->data = index->data;
              index->data = temp;
          }
          index = index->next;
      }
      cur = cur->next;
  }
  return head;
}

Linkedlist *SelectionSortLlist(Linkedlist *head)
{
    Linkedlist *p,*q;
    p = head;
    
    while(p!= NULL)
    {
        q = p->next;
        while(q != NULL)
        {
            if(q->data > p->data)
            {
                int k = q->data;
                q->data = p->data;
                p->data = k;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}

void PrintList(Linkedlist *head)
{
    Linkedlist *temp = head;
    if(temp == NULL){
        printf("It's empty list!\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("Null\n");
}

int main()
{
    Linkedlist *head = NULL;
    head = InsertNode(head,1);
    head = InsertNode(head,4);
    head = InsertNode(head,3);
    head = InsertNode(head,2);
    head = InsertNode(head,5);
    printf("Original Llist : ");
    PrintList(head);
    head = RemoveNode(head,2);
    printf("Llist after removing data %d : ",2);
    PrintList(head);
    head = ReverseLlist(head);
    printf("Reverse Llist : ");
    PrintList(head);
    head = BubbleSortLlist(head);
    printf("BubbleSort Llist : ");
    PrintList(head);
    head = SelectionSortLlist(head);
    printf("SelectionSort Llist : ");
    PrintList(head);

    char a[]="sa";
    int *p =(int*)a;
    //printf("%c\n",*p+1);
    printf("%c",*p++);
    return 0;
}
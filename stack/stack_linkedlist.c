#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// practice stack implementation
// sstack follows LIFO rule

typedef struct stack_node{
    int data;
    struct stack_node *next;
}Stack_node;

typedef struct stack_list{
    Stack_node *stack_top;
}Stack_list;

bool IsEmpty(Stack_list *stack)
{
    if (stack->stack_top == NULL)
    {
        return true;
    }else return 0;
}

Stack_list *Push(Stack_list *stack, int data){
    Stack_node *new_node ;
    new_node = (Stack_node *)malloc(sizeof(Stack_node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(IsEmpty(stack))
    {
        stack->stack_top = new_node;
    }else
    {
        // insert at front
        new_node->next = stack->stack_top;
    }
    stack->stack_top = new_node;
    return stack;
}

Stack_list *Pop(Stack_list *stack)
{
    Stack_node *temp;
    if (IsEmpty(stack))
    {
        printf("Stack is empty to Pop!\n");
    }else
    {
        temp = stack->stack_top;
        printf("Pop stack : %d\n",temp->data);
        stack->stack_top =stack->stack_top->next;
        free(temp);
    }
    return stack;
}

void PrintStack(Stack_list * stack){
    if(stack->stack_top == NULL)
    {
        printf("Stack is empty!\n");
    }else
    {
        Stack_node *temp = stack->stack_top;
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        free(temp);
    }
}

int main()
{
    //creat stack
    Stack_list *stack;
    stack = (Stack_list*)malloc(sizeof(Stack_list));
    printf("Original stack : \n");
    stack = Push(stack,1);
    stack = Push(stack,2);
    stack = Push(stack,3);
    stack = Push(stack,4);
    stack = Push(stack,5);
    PrintStack(stack);
    printf("Stack after Pop : \n");
    stack = Pop(stack);
    PrintStack(stack);
    printf("Stack after Pop : \n");
    stack = Pop(stack);
    PrintStack(stack);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node *NewNode(int data);
Node *InsertLeftNode(Node *root,int data);
Node *InsertRightNode(Node *root,int data);
void Inorder_traversal(Node *root);

Node *NewNode(int data){
    Node *New_node = (Node*)malloc(sizeof(Node));
    New_node->data = data;
    New_node->left = NULL;
    New_node->right = NULL;
    return New_node;
}

Node *InsertLeftNode(Node *root,int data){
    root->left = NewNode(data);
    return root->left;
}

Node *InsertRightNode(Node *root,int data){
    root->right = NewNode(data);
    return root->right;
}

void Inorder_traversal(Node *root){
    if(root == NULL) return;
    Inorder_traversal(root->left);
    printf("%d ->",root->data);
    Inorder_traversal(root->right);
}

int main()
{
    Node* root = NewNode(1);

    root->left = InsertLeftNode(root,2);
    root->right = InsertRightNode(root,3);

    root->left->left = InsertLeftNode(root->left,4);
    root->left->right = InsertRightNode(root->left,5);

    root->right->right = InsertRightNode(root->right,6);

    Inorder_traversal(root);
    return 0;
}
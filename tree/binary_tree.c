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

//left_node -> root -> right_node 
void Inorder_traversal(Node *root){
    if(root == NULL) return;
    Inorder_traversal(root->left);
    printf("%d ->",root->data);
    Inorder_traversal(root->right);
}

//root -> left_node -> right_node
void Preorder_traversal(Node *root){
    if(root == NULL) return;
    printf("%d ->",root->data);
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}

//left_node -> right_node -> root
void Postorder_traversal(Node *root){
    if(root == NULL) return;
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    printf("%d ->",root->data);
}

//if the node doesnt have any child, then it's leaf 
int Isleaf(Node *node){
    if(node->left == NULL && node->right == NULL)
    {   
        //is leaf
        return 1;
    }else{
        //is not leaf
        return 0;
    }
}

//find max 
int get_max(int a,int b){
    return (a>b)? a:b;// if a > b then return a, otherwise return b
}

int get_height(Node *node){
    int left_h=0,right_h=0,max;
    //if a is null or leaf, then height = 1
    if(node == NULL || Isleaf(node))
    {
        return 1;
    }else
    {
        left_h = get_height(node->left);
        right_h = get_height(node->right);
        max=get_max(left_h,right_h);
        return(max+1);
    }
}

int main()
{
    //               6
    //              / \
    //             4   7
    //            / \   \
    //           3   5   8
    
    Node* root = NewNode(6);

    root->left = InsertLeftNode(root,4);
    root->right = InsertRightNode(root,7);

    root->left->left = InsertLeftNode(root->left,3);
    root->left->right = InsertRightNode(root->left,5);

    root->right->right = InsertRightNode(root->right,8);

    printf("Inorder traversal : \n");
    Inorder_traversal(root);
    printf("Preorder traversal : \n");
    Preorder_traversal(root);
    printf("Postorder traversal : \n");
    Postorder_traversal(root);
    printf("\n");
    int height = get_height(root);
    printf("Tree height : %d\n",height);
    return 0;
}
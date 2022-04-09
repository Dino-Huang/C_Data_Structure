#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}Node;

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
    //if tree is null then height = 1
    if(node == NULL)
    {
        return 0;
    }else
    {
        left_h = get_height(node->left);
        right_h = get_height(node->right);
        max=get_max(left_h,right_h);
        return(max+1);
    }
}

Node *SearchNode(Node *root,int data){
    //Node* temp;

    while(root!=NULL)
    {
        if(root->data == data)
        {
            return root;
        }
        else
        {
            Node* temp = SearchNode(root->left,data);
            if(temp!=NULL) 
            {
                return temp;
            }else
            {
                temp = SearchNode(root->right,data);
                return temp;
            }
        }
    }
   return NULL;
}

bool IsFullBinaryTree(Node *root){
    /* A full Binary tree is a special type of binary tree
       in which every parent node/internal node has either 
       two or no children.
    */
    if(root == NULL)
    {
        return true;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    if((root->left) && (root->right))
    {
        return (IsFullBinaryTree(root->left)&&IsFullBinaryTree(root->right));
    }
    return false;
}

int count_of_nodes(Node *root){
    if(root == NULL)
        return 0;
    // number of nodes = root + number of nodes of left subtree
    //                        + number of nodes of right subtree    
    return 1+count_of_nodes(root->left)+count_of_nodes(root->right);
}

bool IsPerfectBinaryTree(Node *root){
    /*
       A perfect binary tree is a type of binary tree in which
       every internal node has exactly two child nodes and all 
       the leaf nodes are at the same level.
    */

    // if a tree is perfect then number of nodes = pow(2,h-1)

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    printf("height of tree : %d\n",get_height(root));
    printf("nodes of tree : %d\n",count_of_nodes(root));
    return (pow(2,get_height(root))-1 == count_of_nodes(root));
    
}

bool IsCompleteBinaryTree(Node *root,int index,int number_nodes)
{
    /* 1.All the nodes on last level must lean towards the left.
       2.The last leaf element might not have a right sibling 
       i.e. a complete binary tree doesn't have to be a full binary tree.
    */
   // Check if the tree is complete
    // An empty tree is complete
    if (root == NULL)
        return (true);
 
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
 
    // Recur for left and right subtrees
    return (IsCompleteBinaryTree(root->left, 2*index + 1, number_nodes) &&
            IsCompleteBinaryTree(root->right, 2*index + 2, number_nodes));
}

int IsBalancedBinaryTree(Node *root){
    /*
    An empty tree is height-balanced. 
    A non-empty binary tree T is balanced if: 
      1) Left subtree of T is balanced 
      2) Right subtree of T is balanced 
      3) The difference between heights of left subtree and right subtree is not more than 1. 
    */
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
 
    /* If tree is empty then return true */
    if (root == NULL)
        return 1;
 
    /* Get the height of left and right sub trees */
    lh = get_height(root->left);
    rh = get_height(root->right);
   

    if ((abs(lh - rh) <= 1) && IsBalancedBinaryTree(root->left)&& IsBalancedBinaryTree(root->right))
        return 1;
 
    /* If we reach here then tree is not height-balanced */
    return 0;
}

int main()
{
    //               1
    //              / \
    //             2   3
    //            /\   /\
    //           4  5 6 
    //          /
    //         7
    
    Node* root = NewNode(1);
	root->left = NewNode(2);
    root->right = NewNode(3);
    //root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    //root->right->left = NewNode(6);
    //root->left->left->left = NewNode(7);

    printf("Inorder traversal : \n");
    Inorder_traversal(root);
    printf("\n");
    printf("Preorder traversal : \n");
    Preorder_traversal(root);
    printf("\n");
    printf("Postorder traversal : \n");
    Postorder_traversal(root);
    printf("\n");
    int height = get_height(root);
    printf("Tree height : %d\n",height);
    Node *NodeDetected = SearchNode(root,9);
    if(NodeDetected!=NULL)
    {
        printf("find noed , data : %d\n",NodeDetected->data);
    }else
    {
        printf("Not found in tree!\n");
    }
    if(IsFullBinaryTree(root))
    {
        printf("Tree is full binary tree!\n");
    }else
    {
        printf("Tree is not full binary tree!\n");
    }
    if(IsPerfectBinaryTree(root))
    {
        printf("Tree is perfect binary tree!\n");
    }else
    {
        printf("Tree is not perfect binary tree!\n");
    }
    int h=count_of_nodes(root);
    int index = 0;
    if(IsCompleteBinaryTree(root,index,h))
    {
        printf("Tree is complete binary tree!\n");
    }else
    {
        printf("Tree is not complete binary tree!\n");
    }

    if(IsBalancedBinaryTree(root))
    {
        printf("Tree is balanced binary tree!\n");
    }else
    {
        printf("Tree is not balanced binary tree!\n");
    }
    return 0;
}
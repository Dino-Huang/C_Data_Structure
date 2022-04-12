#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *left,*right;
    int data;
}Node;

Node *NewNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *Inorder_traversal(Node *root){
    // return null if tree is empty
    if (root == NULL) {
        return NULL;
    }else// if tree is not empty
    {
        Inorder_traversal(root->left);
        printf("%d -->",root->data);
        Inorder_traversal(root->right);
        return 0;
    }
    return NULL;
}

Node *InsertNode(Node *root,int data){
    /* If the tree is empty, return a new node */
    if(root == NULL){
        return NewNode(data);
    }
    /*otherwise recur down the tree*/
    if(data > root->data){
        root->right=InsertNode(root->right,data);
    }else{
        root->left=InsertNode(root->left,data);
    }
    return root;
}

/*find the most left leaf of the node*/
Node *MinValueNode(Node *node){
    Node *current=node;
    while(current->left!=NULL){
        current=current->left;
    }
    return current;
}

/*Inoder to find a node to replace, we need to find the inorder 
successor of the speific node and replace it. 
Successor找的是「right subtree中Key最小的node」
*/
Node *DeleteNode(Node *node,int data){
    // if its a empty tree return node
    if(node == NULL){
        return node;
    }

    //find the node to be delete_node
    if(data < node->data){
        node->left=DeleteNode(node->left,data);
    }else if(data>node->data)
    {
        node->right=DeleteNode(node->right,data);
    }else
    {
        //case 1 : If the node is with only one child or no child
        if(node->left==NULL){
            Node *temp = node->right;
            free(node);
            return temp;// it is safe to free Null ptr in c
        }else if(node->right==NULL){
            Node *temp = node->left;
            free(node);
            return temp;
        }

        //case 2 : if the node has two children
        //find the in order successor of the nodes
        Node *Successor = MinValueNode(node->right);
        //replace the data with successor to node
        node->data=Successor->data;
        // Delete the inorder successor
        node->right=DeleteNode(node->right,Successor->data);
    }
    return node;
}

int main(){
    Node *root = NULL;
    root = InsertNode(root,8);
    root = InsertNode(root,3);
    root = InsertNode(root,1);
    root = InsertNode(root,6);
    root = InsertNode(root,7);
    root = InsertNode(root,10);
    root = InsertNode(root,14);
    root = InsertNode(root,4);

    printf("Inorder traversal : \n");
    Inorder_traversal(root);
    // delete node 10
    printf("\nInorder traversal  with delete node 10 : \n");
    root=DeleteNode(root,10);
    Inorder_traversal(root);
}

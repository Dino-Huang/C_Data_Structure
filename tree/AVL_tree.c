#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
}Node;

Node* NewNode(int key){
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b){
    return a > b ? a : b;
}

int height(Node *node){
    if (node == NULL) return -1;
    int lh = height(node->left);
    int rh = height(node->right);

    return max(lh, rh)+1;
}

Node *MinValueNode(Node *root){
    Node *current=root;
    while (current->left != NULL) 
    current=current->left;

return current;
}

//swap x and y 
Node* LeftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    
    x->height = height(x);
    y->height = height(y);
    
    return y;
}

Node* RightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    
    x->height = height(x);
    y->height = height(y);
    
    return x;
}

int GetbalanceFactor(Node *N){
    if (N == NULL) return 0;
    return height(N->left)-height(N->right);
}

Node *InsertNode(Node *node,int key){
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(NewNode(key));
 
    if (key < node->key)
        node->left  = InsertNode(node->left, key);
    else if (key > node->key)
        node->right = InsertNode(node->right, key);
    else // Equal keys not allowed
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = GetbalanceFactor(node);
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return RightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return LeftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  LeftRotate(node->left);
        return RightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }
    /* return the (unchanged) node pointer */
    return node;
}

/*1.If nodeToBeDeleted is the leaf node (ie. does not have any child),
    then remove nodeToBeDeleted.*/
/*2.If nodeToBeDeleted has one child, then substitute the contents of 
    nodeToBeDeleted with that of the child. Remove the child.*/
/*3.If nodeToBeDeleted has two children, find the inorder successor w of
    nodeToBeDeleted (ie. node with a minimum value of key in the right subtree).*/
Node *DeleteNode(Node *root,int key){
    // STEP 1: PERFORM STANDARD BST DELETE
    if(root == NULL){ return root; }

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if(key < root->key)
        root->left = DeleteNode(root->left,key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if(key > root->key)
        root->right = DeleteNode(root->right,key);
    
    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if(root->left == NULL || root->right == NULL)
        {
            //return root->left if it exists, otherwise return root->right
            Node *temp = root->left ? root->left : root->right ;

            //if the node has no children
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            //one child case
            else
            {
                root = temp;// Copy the contents of
                            // the non-empty child
            }
            free(temp);
        }else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node *temp = MinValueNode(root);

            root->key = temp->key;

            root->right = DeleteNode(root->right,key);

        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

   //update height of  current node
   root->height =max(height(root->left),height(root->right))+1;

   //GET THE BALANCE FACTOR OF THIS NODE (to
   // check whether this node became unbalanced)

   int Balance = GetbalanceFactor(root);

   int balance = GetbalanceFactor(root);
    if(balance >1 && key < root->left->key){
        return RightRotate(root);
    }
    
    if(balance <-1 && key > root->right->key){
        return LeftRotate(root);
    }
    
    if(balance > 1 && key > root->left->key){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    
    if(balance < -1 && key < root->left->key){
        root->right = LeftRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

void InOrderPrint(Node *root)
{
    if(root!=NULL){
        InOrderPrint(root->left);
        printf("%d->",root->key);
        InOrderPrint(root->right);
    }
}

int main(){
    Node *root =NULL;

    root = InsertNode(root, 2);
    root = InsertNode(root, 1);
    root = InsertNode(root, 7);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);
    root = InsertNode(root, 3);
    root = InsertNode(root, 8);

    InOrderPrint(root);

    root = DeleteNode(root,3);
    printf("\nAfter delete node 3 : \n");
    InOrderPrint(root);

    return 0;
}
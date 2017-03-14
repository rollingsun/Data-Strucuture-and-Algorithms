
// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 
struct node
{
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
// C program to demonstrate delete operation in binary search tree

// A utility function to do inorder traversal of BST

/* A utility function to insert a new node with given key in BST */

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */

 
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */

 
void inorder(node* root){
	if(root!=NULL){
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
	}
}

node* insert(node* root, int d)
{
	if(root==NULL)
		newNode(d);
	if(root->key<d)
		root->right=insert(root->right, d);
	else
		root->left=insert(root->left, d);
	return
		root;		
}

node* findmin(node* root)
{
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

void deletenode(node* root, int data){
	if(root==NULL)
		return(root);
	if(root->key>data){
		root->left=deletenode(root->left);
	}
	else if(root->key<data){
		root->right=deletenode(root->right);
	}
	else{
		if(root->left==NULL && root->right=NULL)
				return root;

		else if(root->right==NULL)
		{
				node* temp=root;
				root=root->left;
				free(temp)
		}
	else if(root->left==NULL)
		{
				node* temp=root;
				root=root->right;
				free(temp)
		}
		else {
			node* temp;
			temp=findmin(root);
			root->data=temp->data;
			free(temp);

		}

	}
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    /*printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
	*/ 
    return 0;
}
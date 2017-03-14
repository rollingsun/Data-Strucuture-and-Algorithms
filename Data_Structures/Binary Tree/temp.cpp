
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
static int count=0;
static int lC=0;

struct node
{
	int data;
	node* left;
	node* right;
};

node* newnode(int d){
	node* new_node=(node* )malloc(sizeof(node));
	new_node->data=d;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

node* insert(node* root, int key){
	if(root==NULL){
		count++;
		return newnode(key);
	}
	else if(root->data>key){
		root->right=insert(root->right, key);
	}
	else
		root->left=insert(root->left, key);
}

void inorder(node* root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void leaves(node* root){
	if(root->left==NULL && root->right==NULL){
		lC++;
		return;
	}
	else if(root->left!=NULL){
		leaves(root->left);	
	}
	else {
		leaves(root->right);
	}
}



int main(){
	node* root;
	root=insert(root, 3);
	insert(root, 23);
	insert(root, 2);
	insert(root, 67);
	insert(root, 9);
	inorder(root);
	cout<<"leaves"<<lC<<endl;
	return 0;
}
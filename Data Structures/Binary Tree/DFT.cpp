#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* createNode(int d){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void printpreorder(node* root){
	if(root==NULL)
		return;
	printpreorder(root->left);
		cout<<root->data<<" -> ";	
	printpreorder(root->right);
}


int main(){
	node* root=createNode(1);
	root->left=createNode(2);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right=createNode(3);
	printpreorder(root);
return 0;
}
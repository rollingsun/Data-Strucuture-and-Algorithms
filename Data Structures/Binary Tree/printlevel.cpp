
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int h=0;

struct node
{
	int data;
	node* left;
	node* right;
};

node* newNode(int d){
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

int height(node* tree){
		if(tree==NULL)
			return 0;
		else{
			int lheight=height(tree->left);
			int rheight=height(tree->right);
			if(lheight>rheight)
				return (lheight+1);
			else
				return(rheight+1);
		}

		}


/*
void printlevel(node* tree, int l){
	if(tree==NULL)
		return;
	if(l==1)
		printf("%d\n",tree->data);
	else
}

void printlevelorder(node* tree, int level){
	for (int i = 0; i < level; ++i)
	{
		printlevel();
	}
}
*/
int main()
{
     struct node *root  = newNode(1);
     root->left         =newNode(2);
     root->right        = newNode(3);
     root->left->left   = newNode(4);
     root->left->right  = newNode(5);
     printf("\nPreorder traversal of binary tree is \n");
     printpreorder(root);
     int h=height(root);
     cout<<"h is "<<h<<endl;
     return 0;
}

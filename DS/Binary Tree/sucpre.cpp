#include <iostrea>
using namespace std;

node* search(node* root, node* prev, int data){
	if(root==NULL || root->key==data)
		return root;
	else if(root->data>key)
		search(root->left, root, data)
	else
		search(root->right, root, data)
	return prev;
}

int min(node* root){
	while(root->left!=NULL)
		root=root->left;
	return root->data;
}


int max(node* root){
	if(root==NULL)
		return root;
	while(root->right!=NULL)
		root=root->right;
	return root->data;
}

node* parent(node* root, node* current, int key){
	node* temp=root;
	node* successor=NULL;
	while(current!=temp)
		if(temp->data>key)
				{
					successor=temp;
					temp=temp->left;
				}
		else(temp->data<key)
		{
			temp=temp->right;
		}
}

int successor(node* root,int key){
	node* current=search(root, key);
	if(current->right!=NULL)
		int suc=min(current->right);
	if(current->right==NULL)
		node* parentnode=parent(root, data)
}
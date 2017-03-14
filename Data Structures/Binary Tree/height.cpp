#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct node{
	int data;
	node* left, *right;
};



node* createnode(int d){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
}

int height(node* root){
	if(root==NULL)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}

int diameter(node* root){
	if(root==NULL)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}


void BFS(struct node* root)
{
queue<node*> q;
q.push(root);
while(!q.empty())
{
    node *s=q.front();
    if(s==NULL)
    return;
    q.pop();
    cout<<s->data;
    q.push(s->left);
    q.push(s->right);
}
}

int main(){
	node * root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	root->left->left=createnode(4);
	root->left->right=createnode(5);

	BFS(root);
	cout<<"height "<<height(root)<<endl;
	return 0;
}
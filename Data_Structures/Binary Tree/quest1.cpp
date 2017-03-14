#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* CreateNode(int d){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* CreateTree(){
	cout<<"Enter the size of tree: "<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter data for all the nodes "<<endl;
	int i=0;
	while(i!=n){
		cin>>arr[i];
		i++;
	}
	node *root=CreateNode(arr[i]);
	node* temp;
	while(i!=n-2){
		if(temp->left==NULL){
			i++;
			temp->left=CreateNode(arr[i]);
		}

		else if(temp->right==NULL){
			i++;
			temp->right=CreateNode(arr[i]);
		}

		else{
			temp=temp->left;
		}
	}
	return root;
}

int main(){
	CreateTree();
return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct node {
	int data;
	struct node* next;
}node;


node* CreateNode(){
	return ((node *)malloc(sizeof(node)))		;
}

node* CreateList(){
	int newdata;
 	node *head=CreateNode();
 	node *ptr=head;
 	while(true){
 		cout<<"Input the node data"<<endl;
 		cin>>newdata;
 		ptr->data=newdata;
 		char q;
 		cout<<"Do you want to create another node??"<<endl<<"Input y for yes n for no"<<endl;
 		cin>>q;
 		if(q=='y'){
 			ptr->next=CreateNode();
 			ptr=ptr->next;
 		}
 		else{
 			ptr->next=NULL;
 			break;
 		}
 	}

 	return head;
}

node* keyPtr(struct node* head, int key){
	node *ptr=head;

	while(ptr!=NULL){
		if(ptr->data==key){
			return ptr;
		}
		else
			ptr=ptr->next;
	}
	if(ptr==NULL)
		cout<<"Key not found "<<endl;
}	

void PrintList(node *head){
	node *temp=head;
	do{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	while(temp->next!=NULL);
	cout<<temp->data<<endl;
}


int main(){
	int k;
	int t;
	cout<<" \t\tCreate your linked list"<<endl;
	node* head=CreateList();
	cout<<"\t\t linked list is created"<<endl;
	cout<<"Input value of key : ";
	cin>>k;
	cout<<"Input value you want to insert : ";
	cin>>t;
	afterKey(head, t, k);
	return 0;
}
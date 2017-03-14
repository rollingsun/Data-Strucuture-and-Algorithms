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

struct node* CreateList(){
	struct node* head= CreateNode();
	struct node* ptr1=head;
	int d;
	char a;
	int size;
	cout<<"Input the size of Linked list"<<endl;
	cin>>size;
	int n=size;
	while(size!=0){
		cout<<"Enter the value of node"<<endl;
		cin>>d;
		ptr1->data=d;
		if(size==n){
			ptr1->next=CreateNode();
			ptr1=ptr1->next;
		}

		else if(size!=1){
			ptr1->next=CreateNode();
			ptr1=ptr1->next;
		}
		else if(size==1){
			ptr1->next=NULL;
			break;
		}
		size--;
	}
	return head;
}

node* keyPtr(struct node* head, int key){
	node *ptr=head;
	node* prev=NULL;
	if(ptr->data==key){
		return head;
	}
	while(ptr!=NULL){
		if(ptr->data==key){
			return prev;
		}
		else{
			prev=ptr;
			ptr=ptr->next;
		}
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
	node* ptr=keyPtr(head, k);
	if(ptr==head){
		cout<<"Key has no prev node"<<endl;
		cout<<"Addr of key"<<ptr<<endl;
	}
	else{
	cout<<"prev key is "<<ptr<<endl;
	cout<<"Addr of key "<<ptr->next<<endl;
	}
	return 0;
}
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

void insertSort(struct node** head, int d){
	struct node* newnode=CreateNode();
	struct node *temp=*head;
	struct node* prev;
	while(true){
		if(d<=(*head)->data){
			newnode->data=d;
			newnode->next=*head;
			*head=newnode;
			break;
		}
		else{
		while(temp->data<=d){
			prev=temp;
			temp=temp->next;
		}
		newnode->next=prev->next;
		newnode->data=d;
		prev->next=newnode;
		}
		break;
	}
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
	cout<<" \t\tCreate your sorted linked list"<<endl;
	node* head=CreateList();
	cout<<"\t\t linked list is created"<<endl;
	cout<<"Input value you want to insert : ";
	cin>>t;
	insertSort(&head, t);
	PrintList(head);
	return 0;
}
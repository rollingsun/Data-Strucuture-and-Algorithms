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

node* Create(){
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
 		else if(q=='n'){
 			ptr->next=NULL;
 			break;
 		}
 		else{
 			cout<<"Wrong input. Enter again!! "<<endl;
 		}
 	}
 	cout<<"\t\t****Your linked list is created.****\n"<<endl;
 	return head;
}

void Count(node * head){	
	int i=0;
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		i++;
	}
	cout<<"Length of the linked list is "<<i<<endl;
}


void Modify(node *ptr) {
	cout<<"--Modify list--"<<endl;
	int c=1;
	while(ptr!=NULL){
		cout<<"Enter new data for the node "<<c<< " :"<<endl;
		cin >> ptr->data;
		ptr = ptr->next;
		c++;
	}
}

void Print(node *head){
	node *temp=head;
	do{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	while(temp->next!=NULL);
	cout<<temp->data<<endl;
}

int main(){
	node* head=Create();
	Count(head);
	return 0;
}
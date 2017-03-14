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

void Count(node * head){
	int i=0;
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		i++;
	}
	cout<<"Length of the linked list is "<<i<<endl;
}


void modifyList(node *ptr) {
	cout<<"--Modify list--"<<endl;
	int c=1;
	while(ptr!=NULL){
		cout<<"Enter new data for the node "<<c<< " :"<<endl;
		cin >> ptr->data;
		ptr = ptr->next;
		c++;
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

/*printing extra 1 and 0, needs to be fixed*/
node* Createsort(){
	node * head=CreateNode();
	node *ptr=head;
	int s;
	cout<<"Input the size of list "<<endl;
	cin>>s;	
	int a[s];
	int i=0;
	for (i=0;i<s;i++){
		cout<<"Enter the value of node "<<endl;
		cin>>a[i];
	}
	sort(a, a+s);
	for (i=0;i<s;i++){
	if (i==(s-1))
	{
	ptr->data=a[i];
	ptr->next=NULL;	
	} 
	ptr->data=a[i];
	ptr->next=CreateNode();
	ptr=ptr->next;
	}

	return head;
}

void afterKey(struct node* head, int data, int key){
	node *ptr=head;

	while(ptr!=NULL){
		if(ptr->data==key){
			node* newnode=CreateNode();
			newnode->data=data;
			newnode->next=ptr->next;
			ptr->next=newnode;
			break;
		}
		else
			ptr=ptr->next;
	}
}	

void beforeKey (struct node** head, int d, int key){
	struct node *ptr=*head;
	struct node *prev;

	if((*head)->data==key){
			node* newnode=CreateNode();
			newnode->next=*head;	
			newnode->data=d;
			*head=newnode;
	}

	else{
	while(ptr!=NULL){
		if(ptr->data==key){
			node* newnode=CreateNode();
			newnode->data=d;
			newnode->next=ptr;	
			prev->next=newnode;
			}
		prev=ptr;
		ptr=ptr->next;
			}		
	}
}

void insertatK(struct node* head, int d, int K){
	int i=1;
	struct node* newnode=CreateNode();
	struct node* temp=head;
	struct node* prev;
	while(true){
		if(K==1){
			newnode->data=d;
			newnode->next=head;
			head=newnode;
			break;
		}
		else if (i==K && K>2)
		{
			newnode->data=d;
			newnode->next=prev->next;
			prev->next=newnode;
			break;
		}
		prev=temp;
		temp=temp->next;
		i++;
	}
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

int main(){
	node* head=CreateList();
	modifyList(head);
	PrintList(head);
	return 0;
}
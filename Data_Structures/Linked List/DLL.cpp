#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* CreateNode(){
	return ((node *)malloc(sizeof(node)))		;
}

struct node* DLL(){
	struct node* head= CreateNode();
	struct node* ptr1=head;
	struct node* ptr2=NULL;
	int d;
	char a;
	while(true){
		cout<<"Enter the value of node"<<endl;
		cin>>d;
		ptr1->data=d;
		cout<<"Do you want to create node | y for yes, n for no "<<endl;
		cin>>a;
		if(a=='y'){
			ptr1->next=CreateNode();
			ptr2=ptr1;
			ptr1=ptr1->next;
			ptr1->prev=ptr2;
		}
		else if(a=='n'){
			ptr1->next=NULL;
			ptr1->prev=ptr2;
			head->prev=ptr1;
			break;
		}
	}
	return head;
}

void printDLL(struct node* head){
	struct node* ptr3=head;
	ptr3=ptr3->prev;
	do{
		cout<<ptr3->data<<endl;
		ptr3=ptr3->prev;
	}
	while(ptr3!=head->prev);
}

int main(){
	struct node* head=DLL();
	printDLL(head);
	return 0;
}
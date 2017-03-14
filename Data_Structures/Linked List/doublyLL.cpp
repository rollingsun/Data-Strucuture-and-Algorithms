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

	while(true){
		cout<<"Enter the value of node"<<endl;
		int d;
		char a;
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
		else{
			ptr2=ptr1;
			ptr1->next=NULL;
			ptr1->prev=ptr2;
		}
	}
}

void printDLL(struct node* head){
	struct node* ptr1=head;
	while(ptr1!=NULL){
		cout<<ptr1->data<<endl;
		ptr1=ptr1->next;
	}
}

int main(){
	struct node* head=DLL();
	printDLL(head);
	return 0;
}
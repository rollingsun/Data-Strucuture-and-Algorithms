#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
	int data;
	node* next;
};

void create_sort(node* head){
	node* ptr=head;
	node* prev;
	int d=head->data;
	int t;
	while(ptr!=NULL){
		if(d>(ptr->data))
		{
			ptr->data=t;
			ptr->data=prev->data;
			prev->data=t;
		}
		prev=ptr;
		ptr=ptr->next;
	}

}

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
	create_sort(head);
	Print(head);

return 0;
}
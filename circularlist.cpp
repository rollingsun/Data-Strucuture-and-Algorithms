#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* Node;

 void push(struct node ** head_ref, int value){
 	Node newnode=(node *)malloc(sizeof(struct node));
 	struct node *last=*head_ref;
 	newnode->data=value;
 	newnode->next=*head_ref;
 	*head_ref=newnode;

 	while(last->next!=*head_ref){
 		last=last->next;
 	}

 	}


void Print(Node head){
	struct node* temp=(node *)malloc(sizeof(struct node));
	temp=head;

	while(temp->next!=head){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}


 int main(){
 	struct node* head=NULL		;
 	push(&head, 3);
 	push(&head, 6);
 	push(&head, 9);
 	push(&head, 1);

 	return 0;
 	 }

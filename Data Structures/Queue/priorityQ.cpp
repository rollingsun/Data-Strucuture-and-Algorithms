#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	int priority;
	node* next;
};

node* Createnode(int d, int p){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->priority=p;
	return newnode;
}

/*
Queue* CreateQ(){
	Queue* q=(Queue*)malloc(sizeof(Queue));
	q->back=NULL;
	q->front=NULL;
	return q;
}
*/

void push(node** head, int d, int p){
	node* newnode=Createnode(d, p);
		newnode->data=d;
		newnode->priority=p;
	if(head==NULL){
		*head=newnode;
		newnode->next=NULL;
		}
	else{
			if((*head)->priority<p){
			newnode->next=*head;
			*head=newnode;
			}

			else{
				node* temp=*head;
				node* prev=NULL;
				while(p<temp->next->priority || temp->next!=NULL){
					prev=temp;
					temp=temp->next;
				}
				prev=newnode;
				newnode->next=temp;
			}
		}
	}	

int pop(node** head){
	int t=(*head)->data;
	node* temp=*head;
	*head=(*head)->next;
	free(head);
	return t;
}

int main(){
	node* head=NULL;
	push(&head, 1, 10);
	push(&head, 2, 9);

	return 0;
}
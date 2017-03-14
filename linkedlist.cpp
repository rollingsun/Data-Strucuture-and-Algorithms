#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

typedef struct node* Node;	

void pushNew(struct node **head_ref, int value)
{
	Node newnode=(struct node*)malloc(sizeof(struct node));

		newnode->data=value;
		newnode->next=*head_ref;
		*head_ref=newnode;
}


void printList(struct node *head)
{
	struct node* temp=(node *)malloc(sizeof(struct node));
		temp=head;
		while(temp!=NULL){
		cout<<temp->data<<endl;  
        temp = temp->next;  
		}
		cout<<temp->data<<endl;
			
};



int main(){
	struct node* head=NULL;
	pushNew(&head, 1);
	pushNew(&head, 5);
	pushNew(&head, 7);
	pushNew(&head, 2);

	printList(head);

	return 0;

}
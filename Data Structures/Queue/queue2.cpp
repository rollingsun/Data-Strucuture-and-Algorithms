#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
	
};

struct queue
{
	node* front;
	node* back;
};

node* createnode(int k){
	node* newnode=(node* )malloc(sizeof(node));
	newnode->next=NULL;
	newnode->data=k;
}

queue* createqueue(){
	queue* q=(queue* )malloc(sizeof(queue));
	q->front=NULL;
	q->back=NULL;
	return q;
}

void add(queue* q,int data){
	node* newnode=createnode(data);
	if(q->front==NULL && q->back==NULL)
		{	q->front=newnode;
			q->back=newnode;
		}	
	else{	
			q->back->next=newnode;
			q->back=newnode;
			newnode->next==NULL;
	}
}

int underflow(queue* q, int data){
	if(q->front==NULL and q->back=NULL)
		return 1;
	else 
		return 0;
}

int remove(queue* q){
	if (underflow(q))
	{
		cout<<"underflow"<<endl;	
	}
	else{
		queue* temp=q->front;
		int t=q->front->data;
		q->front=q->front->next;
		free(temp);
		cout<<"Dequeued "<<t<<endl;
		return t; 
	}


}
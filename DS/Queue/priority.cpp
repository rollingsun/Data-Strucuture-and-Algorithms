#include <iostream>
#include <stdlib.h>
using namespace std;

struct Qnode{
	   int data;
	   int priority;
	   Qnode* next;
};

struct queue{
	   Qnode* front;
	   Qnode* back;
};
queue* createQueue(){
	   queue* q=(queue *)malloc(sizeof(queue));
	   q->front=NULL;
	   q->back=NULL;
	   return q;
}

Qnode* createnode(int key, int p){
	   Qnode* newnode=(Qnode* )malloc(sizeof(Qnode));
	   newnode->data=key;
	   newnode->priority=p;
	   newnode->next=NULL;
	   return newnode;
}

void addP(queue* q,int key, int p){
	Qnode* newnode=createnode(key, p);
	 if(q->front==NULL && q->back==NULL ){
  	 				    q->front=newnode;
						q->back=newnode;	 	
	 }
	 else{
	 	  q->back->next=newnode;
	 	  q->back=newnode;
	 }
}

int remove(queue *q, int p){
	Qnode* prev=NULL;
	Qnode* temp=q->front;
	
	if(q->front==NULL && q->back==NULL){
		return -111111;
	}
	
	while(temp->priority!=p){
		prev=temp;
		temp=temp->next;
	}
 	int t=temp->data;
	
	if(q->front==q->back){
	     free(temp);
	     free(prev);
	}
	else if(q->front==temp){
		q->front=q->front->next;
	}
	
	else if(temp==q->back){
		 q->back=prev;
		 q->back->next=NULL;
	}
	else{
		prev->next=temp->next;
	}
	return t;
	
	/*if(q->front=temp){
				 q->front=NULL;
				 q->back=NULL;
				 free(temp);
				 free(prev);
				 return t;
	}
	else if(q->front==temp && q->front->next!=NULL)
	{	
		q->front=temp->next;
		free(temp);
		free(prev);
		return t;
	}
	
	else {
		prev->next=temp->next;
		if(prev->next==NULL){
			q->back=prev;
		}
		free(temp);
		free(prev);
		return t;
	}
	*/	
}

void print(queue* q){
	Qnode* temp=q->front;
		while(temp!=NULL){
		cout<<"Node data "<<temp->data<<" node prioritry "<<temp->priority<<endl;
		temp=temp->next;
		}
	}

int main(){
	queue* q=createQueue();
	addP(q, 3, 3);
	addP(q, 4, 1);
	addP(q, 3, 7);
	/*
	addP(q, 4, 1);
	addP(q, 3, 7);
	*/
	cout<<remove(q, 7)<<endl;
	print(q);
	return 0;
}


/*Code for 2D-array representation of priorityqueuesw

#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue{
	int capacity=5;
	int front[5]={0,0,0,0,0};
	int back[5]={0,0,0,0,0};
	int pQ[4][5]={};
	int k[5]={};
};

queue* createqueue(){
	queue* q=(queue*) malloc(sizeof(queue));
	return q;
}

int isEmpty(queue* q, int p){
	if(q->k[p]==0)
		return 1;
	else 
		return 0;
}

int isFull(queue* q, int p){
	if(q->k[p]==5)
		return 1;
	else
		return 0;
}

void addP(queue* q, int data, int p){
	if(isFull(q, p)){
		cout<<"Stack Overflow, give another priority to the number inserted"<<endl;
		return;
	}
	else{
		q->pQ[p][q->front[p]]=data;
		cout<<"Added "<<data<<" of priority "<<p<<endl;
		q->front[p]=(q->front[p]+1)%5;
		(q->k[p])++;
	}
}

int removeP(queue* q, int p){
	if(isEmpty(q,p)){
		cout<<"No data of this priority present. "<<endl;
	}
	else{
		int t=q->pQ[p][q->back[p]];
		cout<<"Removed "<<t<<" of priority "<<p<<endl;
		q->back[p]=(q->back[p]+1)%(5);
		(q->k[p])--;
		return t;		
	}
}

int main(){
	queue* q=createqueue();
	addP(q,1,3);
	addP(q,2,3);
	addP(q,3,3);
	addP(q,4,3);
	addP(q,5,3);
	addP(q,10,1);
	addP(q,11,1);
	addP(q,14,1);
	removeP(q, 3);
	return 0;
}
*/
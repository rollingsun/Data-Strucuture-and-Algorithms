/* Circular array*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue{
	int capacity;
	int front;
	int back;
	int* array;
	int key;
	int k;
};

queue* createqueue(int c){
	queue* q=(queue* )malloc(sizeof(queue));
	q->capacity=c;
	q->front=0;
	q->back=0;
	q->k=0;
	q->array=(int *)malloc(sizeof(q->capacity*sizeof(int)));
	return q;
}

int underflow(queue* q){
	if (q->k==0)
		return 1;
	else
		return 0;
} 	 		

int overflow(queue* q){
	if(q->k==q->capacity)
			return 1;
	else
		return 0;
}

void add(queue* q, int data){
	if(overflow(q)){
		cout<<"Queue overflow"<<endl;
	}
	else{
		q->array[((q->front)%q->capacity)]=data;
		q->front=((q->front+1)%q->capacity);
		q->k++;
	}	
}

int remove(queue* q){
	if(underflow(q)){
		cout<<"Queue underflow"<<endl;
	}
	else {
		int temp=q->array[((q->back)%(q->capacity))];
		if(q->back==q->capacity-1)
			q->back=0;
		else
			q->back=(q->back%q->capacity)+1;
		q->k--;
		}		
}


int main(){
	int size;
	cout<<"Input size of queue "<<endl;
	cin>>size;
	queue* newqueue=createqueue(size);

return 0;
}


/* Linked list

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

*/
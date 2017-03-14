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
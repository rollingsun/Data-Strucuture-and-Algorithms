#include <iostream>
using namespace std;

struct queue{
	int capacity=5;
	int front[5]={0,0,0,0,0};
	int back[5]={0,0,0,0,0};
	int pQ[4][5]={};
	int k[5]={};
};

int isEmpty(queue* q, int p){
	if(q->front[p]==q->back[p])
		return 1;
	else
		return 0;
}

int isFull(queue* q, int p){
	if(q->k[5]==4)
		return 1;
	else
		return 0;
}

void add(queue* q, int data, int p){
	if(isFull(q, p)){
		cout<<"Overflow"<<endl;
		return;
	}
	else{
		q->pQ[p][q->front[p]]=data;
		q->front[p]=(q->front[p]+1)%q->capacity;
		q->k[p]++;
	}
}

int remove(queue* q, int p){
	if(isEmpty(q,p)){
		cout<<"Not present "<<endl;
	}
	else{
		int t=q->pQ[p][q->back[p]];
		q->back[p]=(q->back[p]+1)%q->capacity;
		q->k[5]--;
	}
}

int main(){
	queue* q;
	add(q,2,3);
	add(q,2,3);
	add(q,5,3);
	add(q,1,3);
	add(q,7,3);
	add(q,2,1);
	add(q,6,1);
	add(q,6,1);

	return 0;
}

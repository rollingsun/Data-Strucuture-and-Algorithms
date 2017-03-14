#include<cstdio>
#include<cstdlib>
#define MAX 100

//circular array started
bool overflow(int* arr, int front, int rear, int n)
{
	if(front==0 && rear==n-1) {
		return 1;
	}
	else if(front==rear+1) {
		return 1;
	}
	else {
		return 0;
	}
}

bool underflow(int* arr, int front, int rear, int n)
{
	if(front==-1 && rear==-1) {
		return 1;
	}
	else {
		return 0;
	}
}

void add(int* arr, int data, int& front, int& rear, int n)
{
	if(overflow(arr,front,rear,n)) {
		printf("array is full\n");
	}
	else {
		if(front==-1) {
			front=front+1;
			rear=rear+1;
		}
		else if(rear==n-1) {
			rear=0;
		}
		else {
			rear=rear+1;
		}
		*(arr+rear)=data;
	}
}

int remove(int* arr, int& front, int& rear, int n)
{
	int k;
	if(underflow(arr,front,rear,n)) {
		printf("queue is empty\n");
		return -1;
	}
	else 
	{
		k=*(arr+front);
		if(front==0 && rear==0) {
			front=-1;
			rear=-1;
		}
		else if(front==n-1) {
			front=0;
		}
		else {
			front=front+1;
		}
		return k;
	}
}
//circular array done

//linked list started
struct node{
	int val;
	struct node* next;
};

bool l_overflow(node* arr, node* front, node* rear)
{
	int c=0;
	node* ptr=front;
	while(ptr!=NULL) {
		c++;
		ptr=ptr->next;
	}
	if(c==MAX) {
		return 1;
	}
	else {
		return 0;
	}
}

bool l_underflow(node* arr, node* front, node* rear)
{
	if(front==NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

node* l_add(node* arr, node* front, node* rear, int data)
{
	if(l_overflow(arr,front,rear)) {
		printf("queue is full\n");
	}
	else {
		node* nw=new node;
		nw->val=data;
		nw->next=NULL;
		if(rear!=NULL) {
			rear->next=nw;
		}
		rear=nw;
		return rear;
	}
}

node* l_remove(node *arr, node *front, node *rear)
{
	node* nw=new node;
	if(l_underflow(arr,front,rear)) {
		printf("queue is empty\n");
		nw->val=-1;
		nw->next=NULL;
	}
	else {
		nw->val=front->val;
		nw->next=front->next;
	}
	return nw;
}
//linked list completed

int main()
{
	int n,t;
	//circular array implementation
	printf("CIRCULAR ARRAY IMPLEMETATION\n");
	printf("no. of elements to add: ");
	scanf("%d",&n);
	int* arr=(int*)malloc(n*sizeof(int));
	int front,rear;
	front=rear=-1;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&t);
		add(arr,t,front,rear,n);
	}
	int p;
	printf("no. of elements to remove: ");
	scanf("%d",&p);
	printf("elements removed in order: \n");
	for(int i=0; i<p; i++)
	{
		int k=remove(arr,front,rear,n);
		if(k==-1) {
			break;
		}
		printf("%d\n",k);	
	}
	//circular array implementation done
	
	//linked list implementation
	printf("\nLINKED LIST IMPLEMENTATION\n");
	printf("no. of elements to add: ");
	scanf("%d",&n);
	node* arrr=(node*)malloc(n*sizeof(node));
	node *l_front=NULL;
	node *l_rear=NULL;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&t);
		l_rear=l_add(arrr,l_front,l_rear,t);
		if(l_front==NULL) {
			l_front=l_rear;
		}
	}
	printf("no. of elements to remove: ");
	scanf("%d",&p);
	printf("elements removed in order: \n");
	node* nw=new node;
	for(int i=0; i<p; i++)
	{
		nw=l_remove(arrr,l_front,l_rear);
		if(nw->val==-1) {
			break;
		}
		else {
			l_front=nw->next;
			if(l_front==NULL) {
				l_rear=NULL;
			}
		}
		printf("%d\n",nw->val);	
	}
	// linked list implementation done
	
	return 0;
}

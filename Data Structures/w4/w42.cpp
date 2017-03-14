#include<cstdio>
#include<cstdlib>
#define MAX 100

//linked array representation started
struct node{
	int priority;
	int values;
	struct node* next;
};

int oflow(node* arrays, node* front)
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

int uflow(node* arrays, node* front)
{
	if(front==NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

node* addP(node* arrays, node* front, int data, int prior)
{
	node* nw=new node;
	if(oflow(arrays,front)) {
		printf("queue is full\n");
		nw->values=-1;
		nw->next=NULL;
		return nw;
	}
	else {
		if(front==NULL) {
			nw->priority=prior;
			nw->values=data;
			nw->next=NULL;
			front=nw;
		}
		else {
			node* ptr=front;
			node* save=NULL;
			while(ptr!=NULL && ptr->priority<prior) {
				save=ptr;
				ptr=ptr->next;
			}
			nw->priority=prior;
			nw->values=data;
			if(save==NULL) {
				nw->next=ptr;
				front=nw;
			}
			else {
				save->next=nw;
				nw->next=ptr;
			}
		}
		return front;
	}
}

node* removeP(node* arrays, node* front)
{
	node* nw= new node;
	if(uflow(arrays,front)) {
		printf("queue is empty\n");
		nw->priority=1;
		nw->values=-1;
		nw->next=NULL;
	}
	else {
		nw->priority=front->priority;
		nw->values=front->values;
		front=front->next;
		nw->next=front;
	}
	return nw;
}
//linked array representation completed

//2 dimensional array representaiton started
int a_overflow(int arrays[][MAX], int front[], int rear[], int prior, int mp, int n)
{
	if(prior>mp) {
		return 1;
	}
	else if(front[prior]==0 && rear[prior]==n-1) {
		return 1;
	}
	else if(front[prior]==rear[prior]+1) {
		return 1;
	}
	else {
		return 0;
	}
}

int a_underflow(int arrays[][MAX], int front[], int rear[], int mp)
{
	int i=1;
	while(i<=mp && front[i]==-1) {
		i++;
	}
	if(i>mp) {
		return 1;
	}
	else {
		return 0;
	}
}

void a_addP(int arrays[][MAX], int front[], int rear[], int prior, int mp, int n, int data)
{
	if(a_overflow(arrays,front,rear,prior,mp,n)) {
		printf("queue is full\n");
	}
	else {
		if(rear[prior]==-1) {
			front[prior]=rear[prior]=0;
		}
		else if(rear[prior]==n-1) {
			rear[prior]=0;
		}
		else {
			rear[prior]=rear[prior]+1;
		}
		arrays[prior][rear[prior]]=data;
	}
}

int a_removeP(int arrays[][MAX], int front[], int rear[], int mp, int n)
{
	if(a_underflow(arrays,front,rear,mp)) {
		printf("queue is empty\n");
		return -1;
	}
	else {
		int i=1;
		while(i<=mp && front[i]==-1) {
			i++;
		}
		int k=arrays[i][front[i]];
		if(front[i]==0 && rear[i]==0) {
			front[i]=rear[i]=-1;
		}
		else if(front[i]==n-1) {
			front[i]=0;
		}
		else {
			front[i]=front[i]+1;
			if(front[i]==rear[i]+1) {
				front[i]=rear[i]=-1;
			}
		}
		return k;
	}
}

int main()
{
	int n,t,prior;
	//linked array implementation
	printf("LINKED ARRAY IMPLEMENTATION\n");
	printf("no. of elements to be added in the queue: ");
	scanf("%d",&n);
	printf("enter priority and value: \n");
	node* arrays=(node*)malloc(n*sizeof(node));
	node* front=NULL;
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&prior,&t);
		front=addP(arrays,front,t,prior);
	}
	printf("no. of elements to be removed from the queue: ");
	scanf("%d",&n);
	printf("elements removed are: \n");
	node* nw= new node;
	for(int i=0; i<n; i++)
	{
		nw=removeP(arrays,front);
		if(nw->values==-1) {
			front=NULL;
			break;
		}
		else {
			printf("%d\n",nw->values);
			front=nw->next;
		}
	}
	//linked array implementation done
	
	//2 dimensional array implementation
	printf("\n2 DIMENSIONAL ARRAY IMPLEMENTATION\n");
	printf("no. of elements to be added and max priority: ");
	int mp;
	scanf("%d %d",&n,&mp);
	int arrr[MAX][MAX],ffront[MAX],rrear[MAX];
	for(int i=1; i<=mp; i++)
	{
		ffront[i]=rrear[i]=-1;
	}
	printf("enter the element priority and value: \n");
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&prior,&t);
		a_addP(arrr,ffront,rrear,prior,mp,n,t);
	}
	printf("no. of elements to be removed from the queue: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int k=a_removeP(arrr,ffront,rrear,mp,n);
		if(k==-1) {
			break;
		}
		else {
			printf("%d\n",k);
		}
	}
	//2 dimnesional array representation done
	
	return 0;
}

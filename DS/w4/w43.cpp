#include<cstdio>
#include<cstdlib>
#define MAX 100
#include<bits/stdc++.h>
using namespace std;

//linked list representation started
struct node{
	int val;
	struct node* next;
	struct node* prev;
};

bool oflow(node* left, node* right)
{
	int c=0;
	node* ptr=left;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->next;
	}
	if(c>=MAX) {
		return 1;
	}
	else {
		return 0;
	}
}

bool underflow(node* left, node* right)
{
	if(left==NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

node* addDQ(node* left, node* right, int data, int flag)
{
	node* nw=new node;
	if(oflow(left,right)) {
		printf("queue is full\n");
		nw->val=-1;
		return nw;
	}
	else {
		nw->val=data;
		if(flag==0) {
			nw->next=left;
			nw->prev=NULL;
			if(left!=NULL) {
				left->prev=nw;
			}
			left=nw;
			return left;
		}
		else {
			nw->next=NULL;
			nw->prev=right;
			if(right!=NULL) {
				right->next=nw;
			}
			right=nw;
			return right;
		}
	}
}

node* removeDQ(node* left, node* right, int flag)
{
	if(underflow(left,right)) {
		printf("queue is empty\n");
	}
	else {
		node* nw=new node;
		if(flag==0) {
			nw->val=left->val;
			left=left->next;
			nw->next=left;
		}
		else {
			nw->val=right->val;
			nw->next=right->prev;
			right=right->prev;
		}
		return nw;
	}
}
//linked list implementation completed

//linked array implementation started
bool l_overflow(int avail)
{
	if(avail==-1) {
		return 1;
	}
	else {
		return 0;
	}
}

bool l_underflow(int left, int right)
{
	if(left==-1) {
		return 1;
	}
	else {
		return 0;
	}
}

void l_addDQ(int info[], int link[], int& avail, int& left, int&right, int flag)
{
	if(l_overflow(avail)) {
		printf("queue is full\n");
	}
	else {
		int temp=avail;
		avail=link[avail];
		if(flag==0) {
			if(left==-1) {
				left=right=temp;
				link[left]=link[right]=-1;
			}
			else {
				link[temp]=left;
				left=temp;
			}
		}
		else {
			if(right==-1) {
				left=right=temp;
				link[left]=link[right]=-1;
			}
			else {
				link[right]=temp;
				link[temp]=-1;
				right=temp;
			}
		}
	}
}

int l_removeDQ(int info[], int link[], int& avail, int& left, int& right, int flag)
{
	if(l_underflow(left,right)) {
		printf("queue is empty\n");
	}
	else {
		int k;
		if(flag==0) {
			int temp=left;
			left=link[left];
			link[temp]=avail;
			avail=temp;
			k=info[temp];
		}
		else {
			link[right]=avail;
			avail=right;
			k=info[right];
			int ptr=left;
			while(link[ptr]!=right) {
				ptr=link[ptr];
			}
			link[ptr]=-1;
			right=ptr;
		}
		return k;
	}
}
//linked array implementation completed;

int main()
{
	int n,t,p;
	//linked list implementation
	printf("LINKED LIST IMPLEMENTATION\n");
	printf("no. of elements to be added: ");
	scanf("%d",&n);
	node* left=NULL;
	node* right=NULL;
	printf("enter the element and end to which it is to be added (0 for left, 1 for right): \n");
	for(int i=0; i<n; i++)
	{
		scanf("%d %d",&t,&p);
		if(p==0) {
			left=addDQ(left,right,t,p);
			if(right==NULL) {
				right=left;
			}
		}
		else {
			right=addDQ(left,right,t,p);
			if(left==NULL) {
				left=right;
			}
		}
	}
	printf("no. of elements to be removed: ");
	scanf("%d",&n);
	printf("for each element to be removed enter whether from left(0) or right(1): \n");
	node* nw=new node;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&p);
		nw=removeDQ(left,right,p);
		if(nw->val==-1) {
			break;
		}
		if(p==0) {
			left=nw->next;
			if(left==NULL) {
				right=NULL;
			}
		}
		else {
			right=nw->next;
			if(right==NULL) {
				left=NULL;
			}
		}
		printf("%d\n",nw->val);
	}
	//linked list implementation done
	
	//linked array implementation
	printf("\nLINKED ARRAY IMPLEMENTATION\n");
	printf("total no. of elements: ");
	scanf("%d",&n);
	printf("enter array info: \n");
	int arrr[MAX],link[MAX],lleft=-1,rright=-1;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arrr[i]);
	}
	for(int i=0; i<n-1; i++)
	{
		link[i]=i+1;
	}
	link[n-1]=-1;
	int avail=0;
	printf("no. of elements to be added: ");
	scanf("%d",&t);
	printf("enter whether element to be added to left(0) or right(1): \n");
	int k;
	for(int i=0; i<t; i++)
	{
		scanf("%d",&p);
		l_addDQ(arrr,link,avail,lleft,rright,p);
	}
	printf("no. of elements to be removed: ");
	scanf("%d",&k);
	printf("enter whether element to be removed from left(0) or right(1): \n");
	for(int i=0; i<k; i++)
	{
		scanf("%d",&p);
		t=l_removeDQ(arrr,link,avail,lleft,rright,p);
		if(t==-1) {
			break;
		}
		else {
			printf("%d\n",t);
		}
	}
	//linked array implementation done
	
	return 0;
}

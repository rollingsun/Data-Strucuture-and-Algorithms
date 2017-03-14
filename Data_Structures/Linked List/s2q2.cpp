#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	node *next;
};
void create(node**head)
{
	int n;
		printf("No. of nodes : \n");
	scanf("%d",&n);
		printf("data of nodes : \n");
		scanf("%d",&((*head)->next));
		node*nnode=(node*)malloc(sizeof(node));
		(*(*head)).next=nnode;
	
	for(int i=1;i<n-1;i++)
	{
		scanf("%d",&(*nnode).x);
		(*nnode).next=(node*)malloc(sizeof(node));
		nnode=(*nnode).next;
	}
	scanf("%d",&(*nnode).x);
		(*nnode).next=NULL;

}
void printlist(node*c)
{
	while(c!=NULL)
	{
		printf("%d ",(*c).x);
		c=(*c).next;
	}
	printf("\n");
}

void sort(node*head)
{
	node*n;
	node*p=NULL;
	bool swapp;
	do
	{
		n=head;
		swapp=false;
		while((*n).next!=p)
		{
			if(((*n).x)>(*((*n).next)).x)
			{
				swapp=true;
				int temp=(*n).x;
				(*n).x=(*((*n).next)).x;
				(*((*n).next)).x=temp;
			}
			n=(*n).next;
		}
		p=n;
	}while(swapp);
}
int main()
{
	node*head=(node*)malloc(sizeof(node));
	create(&head);
	printf("your list data before sorting : \n");
	printlist(head);
sort(head);
printf("your list data after sorting : \n");
printlist(head);

	
	return 0;
}

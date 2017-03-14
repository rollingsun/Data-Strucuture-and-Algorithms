#include<bits/stdc++.h>
using namespace std;
struct node
{
	int ptr;
	node *next;
};
int create(node**head)
{
	int n;
		printf("Inout the total no of persons 	 \n");
	scanf("%d",&n);
	(*(*head)).ptr=1;
		node*nnode=(node*)malloc(sizeof(node));
		(*(*head)).next=nnode;
	
	for(int i=1;i<n-1;i++)
	{
		(*nnode).ptr=i+1;
		(*nnode).next=(node*)malloc(sizeof(node));
		nnode=(*nnode).next;
	}
        	(*nnode).ptr=n;
		(*nnode).next=*head;
		return n;

}

int josephus(node**head,int n,int k)
{
	node* t=*head;
	node* prev;
	int count1=1;
	int count2=n;
	while(count2!=1)
	{
		
		if((count1%k)==0)
		{
			node*temp=t;
			prev->next=temp->next;
			t=t->next;
			free(temp);
			count2--;
		}
		else
		{
	    prev=t;
		t=t->next;
	   }
	   
	   count1++;
	}

return ((*t).ptr);

}
int main()
{
	int n,k,p;
	node*head=(node*)malloc(sizeof(node));
    n=create(&head);
    printf("value of k :\n");
    scanf("%d",&k);
    if(k==1)
    {
    	printf("person who is alive at the end : person no. %d\n",n);
	}
	else
	{
       int p=josephus(&head,n,k);
      printf("person who is alive at the end : person no. %d \n",p);
    }

return 0;
}

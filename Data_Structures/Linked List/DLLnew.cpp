#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* CreateNode(){
	return ((node *)malloc(sizeof(node)))		;
}

struct node* DLL(){
	struct node* head= CreateNode();
	struct node* ptr1=head;
	struct node* ptr2=NULL;
	int d;
	char a;
	int size;
	cout<<"Input the size of DLL"<<endl;
	cin>>size;
	int n=size;
	while(size!=0){
		cout<<"Enter the value of node"<<endl;
		cin>>d;
		ptr1->data=d;
		if(size==n){
			ptr1->next=CreateNode();
			ptr2=ptr1;
			ptr1=ptr1->next;
			ptr1->prev=ptr2;
		}

		else if(size!=1){
			ptr1->next=CreateNode();
			ptr2=ptr1;
			ptr1=ptr1->next;
			ptr1->prev=ptr2;
		}
		else if(size==1){
			ptr1->next=NULL;
			ptr1->prev=ptr2;
			head->prev=NULL;
			break;
		}
		size--;
	}
	return head;
}

void afterKey(struct node* head, int data, int key){
	node *ptr=head;
	node* prev=NULL;

	while(ptr!=NULL){
		if(ptr->data==key){
			node* newnode=CreateNode();
			newnode->data=data;
			newnode->next=ptr->next;
			newnode->prev=ptr;
			(ptr->next)->prev=newnode;
			ptr->next=newnode;
			break;
		}
		else{
			prev=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
			cout<<"Key not found "<<endl;
	}	
}

void beforeKey (struct node** head, int d, int key){
	struct node *ptr=*head;
	struct node *prev;

	if((*head)->data==key){
			node* newnode=CreateNode();
			newnode->next=*head;	
			newnode->prev=NULL;
			newnode->data=d;
			(*head)->prev=newnode;
			*head=newnode;
	}

	else{
	while(ptr!=NULL){
		if(ptr->data==key){
			node* newnode=CreateNode();
			newnode->data=d;
			newnode->next=ptr;
			ptr->prev=newnode;
			newnode->prev=prev;	
			prev->next=newnode;
			}
		prev=ptr;
		ptr=ptr->next;
			}		
	}
}
void insertatK(struct node** head, int d, int K){
	int i=1;
	struct node* newnode=CreateNode();
	struct node* temp=*head;
	struct node* prev;
	while(true){
		if(K==1){
			newnode->data=d;
			newnode->next=*head;
			newnode->prev=NULL;
			(*head)->prev=newnode;
			*head=newnode;
			break;
		}
		else if (i==K && K>2)
		{
			newnode->data=d;
			newnode->next=prev->next;
			newnode->prev=prev;
			temp->prev=newnode;
			prev->next=newnode;
			break;
		}
		prev=temp;
		temp=temp->next;
		i++;
	}
}

void printDLL(struct node* head){
	struct node* ptr3=head;
	do{
		cout<<ptr3->data<<endl;
		ptr3=ptr3->next;
	}
	while(ptr3!=NULL);
}

int main(){
	int t,k;
	int a;
	struct node* head=DLL();
	cout<<"Which function do you want to use???\n for inserting after key, input 1\n for inserting before key, input 2\n for inserting at Kth position, input 3"<<endl;
	cin>>a;
	if(a==1){
		cout<<"Input value of key : ";
		cin>>k;
		cout<<"Input value you want to insert : ";
		cin>>t;
		afterKey(head, t, k);
		}

	else if(a==2){
		cout<<"Input value of key : ";
		cin>>k;
		cout<<"Input value you want to insert : ";
		cin>>t;
		beforeKey(&head, t, k);
		}

	else if(a==3){
		cout<<"Input postion where u want to insert new node: "<<endl;
		cin>>k;
		cout<<"Input value you want to insert : ";
		cin>>t;
		beforeKey(&head, t, k);
		}

		else{
			cout<<"Wrong input!!"<<endl;
		}
	
	printDLL(head);
	return 0;
}
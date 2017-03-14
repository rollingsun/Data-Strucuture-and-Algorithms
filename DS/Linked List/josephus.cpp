#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int data;
	struct node* next;
};

struct node* CreateNode(){
	return ((node*) malloc(sizeof(struct node)));
}


struct node* CreateCLL(){
	struct node* head=CreateNode();
	struct node* ptr=head;
	cout<<"Enter no of persons"<<endl;
	cin>>n;
	head->data=1;
	cout<<ptr->data<<endl;
	for(int i=0;i<(n-2);i++){
			ptr->next=CreateNode();
			ptr=ptr->next;
			ptr->data=i+2;			
			cout<<ptr->data<<endl;
		}
	ptr->next=CreateNode();
	ptr=ptr->next;
	ptr->data=n;
	cout<<ptr->data<<endl;
	ptr->next=head;	
	return head;
}

int josephusCLL(node* head,int k){
	node* ptr=head;
	node* prev=NULL;
	int count=0;
	int count2=1;
	while(count!=(n-1)){
		if(count2%k==0){
			node* temp=ptr;
			ptr=ptr->next;
			cout<<"count2 "<<count2<<endl;
			cout<<"temp ka data"<<temp->data<<endl;
			free(temp);
			count++;
		}
		else{
			prev=ptr;
			ptr=ptr->next;
		}
		count2++;
	}
	cout<<ptr->data<<endl;
	return ptr->data;
}

/*
void printCLL(struct node* head){
	struct node* ptr=head;
	do{
		cout<<ptr->data<<endl;;
		ptr=ptr->next;
	}
	while(ptr->next!=head);
}

int josephus(int n,int k){
	if(n==1)
		return 1;
	else
		return ((josephus(n-1,k)+k-1)%n+1);
}
*/

int main(){
	int k;
	node* head=CreateCLL();
	cout<<"Input value of k"<<endl;
	cin>>k;
	int ans=josephusCLL(head,k);
	cout<<ans<<endl;
	return 0;
}
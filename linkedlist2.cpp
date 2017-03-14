#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	 struct node* next;
};

node* CreateNode(){
	return ((node*)malloc(sizeof(node)));
}


node* createList(){
	node *head = CreateNode();
	node *p = head;
	while(true){
		cout << "Enter node value" << endl;
		cin >> p->data;
		char c;
		cout << "Do you wish to create another node? [Y/N]" << endl;
		cin >> c;
		if( c=='Y' || c=='y' ){
			p->next = CreateNode();
			p = p->next;
			continue;
		}
		else if( c=='N' || c=='n' ){
			p->next = NULL;
			break;
		}
		else {
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return head;
}


void PrintList(struct node * temp){
	while(temp->next!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<temp->data<<endl;	
}


void Delete(struct node **head, key)
{
node *temp=head;
node *prev=head;

prev->next=temp;

if(key==temp->data){
	head=head->next;
	free(temp);
}

else{
while(key!==temp->next){
temp=temp->next
prev->next=temp->next;	
}	
free(temp)

}


int main(){
	node* head = createList();
	PrintList(head);
	return 0;
}

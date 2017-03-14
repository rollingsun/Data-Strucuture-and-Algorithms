#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

typedef struct node {
	int data;
	node *next;
}node;

node* createNode() {
	return (node*)malloc(sizeof(node));
}

node* createList(){
	node *head = createNode();
	node *p = head;
	while(true){
		cout << "Enter node value" << endl;
		cin >> p->data;
		char c;
		cout << "Do you wish to create another node? [Y/N]" << endl;
		cin >> c;
		if( c=='Y' || c=='y' ){
			p->next = createNode();
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

node* createListSort(){
	int i = 0;
	int A[100] = {0};
	cout << "Enter length of linked list" << endl;
	int N;
	cin >> N;
	for(i=0;i<N;++i) cin >> A[i];
	sort(A,A+N);
	node *head = createNode();
	node *p = head;
	i = 0;
	while(true){
		p->data = A[i++];
		if( i<N ){
			p->next = createNode();
			p = p->next;
			continue;
		}
		else{
			p->next = NULL;
			break;
		}
	}
	return head;
}

void printList(node *p) {
	while(p!=NULL){
		cout << p->data << endl;
		p = p->next;
	}
}

int countList(node *head) {
	node *p = head;
	int ans = 0;
	while(p!=NULL){
		++ans;
		p = p->next;
	}
	return ans;
}

void modifyList(node *p) {
	while(p!=NULL){
		cin >> p->data;
		p = p->next;
	}
}

node* searchList(node *p, int k){
	while(p!=NULL){
		if(p->data == k) return p;
		else p=p->next;
	}
	cout << "No such data found" << endl;
	return NULL;
}

int main(){
	node* head = createListSort();
	printList(head);
	return 0;
}

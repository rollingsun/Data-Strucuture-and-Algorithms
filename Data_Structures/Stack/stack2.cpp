#include<iostream>
#include <stdlib.h>
using namespace std;

struct Stack{
	int capacity;
	int data;
	Stack* next;
};

int underflow(Stack* stack){
	if(stack==NULL){
		return 1;
	}
}
Stack* newnode(){
	return (Stack*)malloc(sizeof(Stack));
}

void* push(Stack** topnode, int d){
	Stack* pushednode=newnode();
	pushednode->data=d;
	pushednode->next=*topnode;
	*topnode=pushednode;
	cout<<"Pushed to stack :"<<pushednode->data<<endl;
}
int pop(Stack** topnode){
	if (underflow(*topnode)){
		return -11111;
	}
	struct Stack* temp=*topnode;
	*topnode=(*topnode)->next;
	int k;
	k=temp->data;
	free(temp);
	cout<<"Popped "<<k<<endl;
	return k;
	
}


int main()
{   Stack* topnode;
	push(&topnode, 2);
	push(&topnode, 8);
	pop(&topnode);
	return 0;
}


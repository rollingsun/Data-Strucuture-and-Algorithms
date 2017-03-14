#include <iostream>
#include <stdlib.h>

using namespace std;

struct Stack{
	int data;
	Stack* next;
};

Stack* Createstack(int data){
	Stack* newnode=(Stack*)malloc(sizeof(Stack));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

int isEmpty(Stack* stacktop){
	if(stacktop==NULL){
		return 1;

}
return 0;
}

Stack* push(Stack** stacktop,int data){	
	Stack* pushedNode=Createstack( data);
	pushedNode->next=*stacktop;
	*stacktop=pushedNode;	
	cout<<"pushed to Stack "<<pushedNode->data<<endl;
}

int pull(Stack** stacktop){
	if (isEmpty(*stacktop)){
		return -111111;
	}
	Stack* temp=*stacktop;
	*stacktop=(*stacktop)->next;
	int val=temp->data;
	free(temp);
	cout<<"Poped value "<<val<<endl; 		
}

int main(){
	Stack* stacktop=NULL;
	push(&stacktop, 2);
	push(&stacktop, 7);
	pull(&stacktop);
	pull(&stacktop);
	return 0;


}
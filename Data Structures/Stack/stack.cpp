#include <iostream>
#include <stdlib.h>

using namespace std;

int INT_MIN=-111111;
struct Stack{
	int top;
	unsigned capacity;
	int* array;	
};

Stack* CreateStack(unsigned capacity){
	Stack* stack=(Stack *)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	return stack;
}

int isFull(Stack *stack){
	return (stack->top==((stack->capacity)-1));
}

int isEmpty(Stack *stack){
	return	(stack->top==-1);
}


void push(Stack* stack, int data){
	if (isFull(stack)){
		return ;
	}
	stack->array[++stack->top]=data;
	cout<<"Push operation completed, pushed "<<data<<endl;
}

int pop(Stack* stack){
	if (isEmpty(stack)){
		return INT_MIN;
	}
	int k= (stack->array[stack->top]);
	(stack->top)--;
	return(k);
}

int main(){
	int capacity=3;
	Stack* stack=CreateStack(capacity);
	int poper=pop(stack);
	cout<<"Popped shit is "<<poper<<endl;
return 0;
}


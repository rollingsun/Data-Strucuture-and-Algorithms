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
}

int pop(Stack* stack){
	if (isEmpty(stack)){
		return INT_MIN;
	}
	int k= (stack->array[stack->top]);
	(stack->top)--;
	return(k);
}

void sort(Stack* stack,int temp){
	if(isEmpty(stack)){
		if(stack->top==-1)
			push(stack, temp);
		else if(temp>poped)
			push(stack, temp);
		else
			push(stack,poped);
	}
	else{
	int poped=pop(stack);
	sort(stack, temp);
	push(stack, poped);
	}
}

void Reverse(Stack* stack){
	if(!isEmpty(stack)){
	int temp=pop(stack);
	Reverse(stack);
	sort(stack, temp);
	}
}

void Print(Stack* stack){
	int k=stack->top;
	while(k>=0){
		cout<<stack->array[k--]<<endl;
	}	
}

int main(){
	Stack* stack=CreateStack(4);
	push(stack, 8);
	push(stack, 1);
	push(stack, 6);
	push(stack, 4);
	Reverse(stack);
	Print(stack);	
return 0;
}


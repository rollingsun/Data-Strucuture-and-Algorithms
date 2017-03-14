#include <iostream>
#include <stdlib.h>

using namespace std;

int INT_MIN=-111111;
struct Stack{
	int top1;
	int top2;
	unsigned capacity;
	int* array;	
};

Stack* CreateStack(unsigned capacity){
	Stack* stack=(Stack *)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top1=-1;
	stack->top2=capacity-1;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	return stack;
}

int isEmpty(Stack *stack){
	return	(stack->top1==-1);
}

int isEmpty2(Stack *stack){
	return	(stack->top2==stack->capacity-1);
}

void push1(Stack* stack, int data){
	if (stack->top1<stack->top2){
		stack->array[++stack->top1]=data;
		cout<<"Push1 operation completed, pushed "<<data<<endl;
	}
	else {
		cout<<"Stack1 is full "<<endl;
		return;	
	
	}
}

void push2(Stack* stack, int data){
	cout<<"top1 is "<<stack->top1<<" top2 is "<<stack->top2<<endl;
	if (stack->top1<stack->top2){
		stack->array[--stack->top2]=data;
		cout<<"Push2 operation completed, pushed "<<data<<endl;
	}
	else{ 
		cout<<"Stack2 is full "<<endl;
		return;
		}	
	}

int pop1(Stack* stack){
	if (isEmpty(stack)){
		return INT_MIN;
	}
	int k= (stack->array[stack->top1]);
	(stack->top1)--;
	return(k);
}

int pop2(Stack* stack){
	if (isEmpty(stack)){
		return INT_MIN;
	}
	int k= (stack->array[stack->top2]);
	(stack->top2)++;
	return(k);
}

int main(){
	int capacity=4;
	Stack* stack=CreateStack(capacity);
	push1(stack, 4);
	push1(stack, 4);
	push1(stack, 2);
	push2(stack, 5);
	push2(stack, 7);
return 0;
}


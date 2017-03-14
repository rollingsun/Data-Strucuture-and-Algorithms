#include<iostream>
#include <stdlib.h>
using namespace std;

template <class vary>

class stack
 {
	int top;
	int capacity;
	int *vary;

int underflow(Stack* stack){
		return (stack->top==-1);
}

int overflow(Stack* stack){
	return (stack->top==stack->capacity-1);
}

public :
Stack(int capacity){
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(vary*)malloc(capacity*(sizeof(vary)));
	return stack;
}

void push(Stack* stack, vary t){
	if (overflow(stack)){
		return;
	}
	stack->array[++(stack->top)]=t;
	cout<<stack->array[(stack)->top]<<" pushed to stack"<<endl;
}

vary pop(Stack* stack){
	if (underflow(stack)){
		return -111111;
	}
	else {
		vary c=stack->array[(stack->top)--];
		cout<<"Popped "<<c<<endl;
	return (c);
}
}

using namespace std;
int main()
{  
	Stack<int> newstack
	push(newstack, 2);
	push(newstack, 4);
	pop(newstack);
	return 0;
}


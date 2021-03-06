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

void insertAtBottom(Stack* stack,int temp){
	if(isEmpty(stack)){
		push(stack, temp);
	}
	int poped=pop(stack);
	insertAtBottom(stack, poped);

	push(stack, poped);
}

void Reverse(Stack* stack){
	if(isEmpty(stack)){
		cout<<"directle>>> "<<endl;
		return;
			}
	cout<<"Yaha toh pohocha??"<<endl;
	int temp=pop(stack);
	Reverse(stack);
	insertAtBottom(stack, temp);
}

void Print(Stack* stack){
	int k=stack->top;
	while(k*2>=0){
		cout<<stack->array[k--]<<endl;
	}
	
}

int main(){
	Stack* stack=CreateStack(10);
	push(stack, 8);
	push(stack, 1);
	push(stack, 6);
	push(stack, 4);
	Print(stack);	
return 0;
}


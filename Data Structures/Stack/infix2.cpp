#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Stack{
	int top;
	int capacity;
	char* array;
};

Stack* Createstack(int k){
	Stack *stack=(Stack* )malloc(sizeof(Stack));
	stack->top=-1;
	stack->capacity=k;
	char *array=(char *)malloc(k*sizeof(int));
	stack->array=array;
	return stack;
}

int isFull(Stack *stack){
	if(stack->top==stack->capacity-1)
		return 1;
	else
		return 0;
}

int isEmpty(Stack *stack){
	if(stack->top==-1)
		return 1;
	else
		return 0;
}

char peek(Stack* stack){
	if(isEmpty(stack))
		return '0';
	else
		return(stack->array[stack->top]);
}

void Push(Stack* stack, int data){
	if(isFull(stack)){
		return;
	}
	stack->array[++((stack)->top)]=data;
	
	}

char Pop(Stack* stack){
	if(isEmpty(stack))
		return 'x';
	return (stack->array[((stack)->top)--]);
	}

int isoperand(char q){
	return((q>='a' && q<='z') || (q>='A' && q<='B')) ;
}

int precedence(char q){
	if(q=='+' || q=='-')
		return 1;

	else if(q=='*' || q=='/')
		return 2;

	else if(q=='^')
		return 3;
	else if(q=='(')
		return 0;
}

string intopost(string infix, Stack* stack){
	int i=0;
	string postfix;
	for(i=0;i<infix.length();i++){
		char q=infix[i];
		if(q==' '){
		}
		else if(isoperand(q)){
			postfix+=q;
		}
		else if(q=='('){
			Push(stack, q);
		}
		else if(q==')'){
			while(peek(stack)!='(' && !isEmpty(stack)){
				postfix+=Pop(stack);
				}
			if(peek(stack)=='(')
				Pop(stack);
			else{
				while(!isEmpty(stack)){
					postfix+=Pop(stack);
				}
			}
			}
		else if(precedence(q)>precedence(peek(stack)) || isEmpty(stack))
				Push(stack, q);
		else{	
			while(precedence(q)<=precedence(peek(stack)) && !isEmpty(stack)){
				postfix+=Pop(stack);
				}
				Push(stack, q);
			}
			
		}
		while(!isEmpty(stack)){
				postfix+=Pop(stack);
				}
	return postfix;
}	

int main(){	
	Stack *stack;
	stack=Createstack(100);
	cout<<"Input the infix string"<<endl;
	string in;
	cin>>in;
	string ans=intopost(in, stack);
	cout<<"after conversion "<<ans<<endl;
	return 0;
}
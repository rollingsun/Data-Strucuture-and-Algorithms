#include<iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Stack{
	int top;
	int capacity;
	char *array;
};

int underflow(Stack* stack){
		return (stack->top==-1);
}

int overflow(Stack* stack){
	return (stack->top==stack->capacity-1);
}
Stack* createStack(int capacity){

	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(char*)malloc(capacity*(sizeof(char)));
	return stack;
}

void push(Stack* stack, char t){
	if (overflow(stack)){
		return;
	}
	stack->array[++(stack->top)]=t;
}

int pop(Stack* stack){
	if (underflow(stack)){
		return -111111;
	}
	return (stack->array[(stack->top)--]);
}

int isOperand(char a){
	if(a>='0' && a<='9')
		return 1;
	else
		return 0;
}

void postCal(Stack* stack, string postfix){
	int len=postfix.length();
	int k;
	
	for(int i=0;i<len;i++){
		char a=postfix[i];
		
		if(isOperand(a)){
			push(stack, a);
			}
		
		else if(a==' '){			
		}

		else {
		int temp2=pop(stack)-'0';	
		int temp=pop(stack)-'0';
		
		switch(a)
	    {
	    case '+':
	       k= temp+temp2;
	    break;
	    case '-':
	       k= temp-temp2;
	    break;
	    case '*':
			k= temp*temp2;
	    break;
	    case '/':
	       k= temp/temp2;
	    break;
	    default:
	    	cout<<"unkonwn op"<<endl;
	    }
	    
	    char c=k + '0';
	    push(stack,c);
		}
		
		}
		cout<<"Answer is "<<k<<endl;
}


using namespace std;


int main()
{	int k=100;
	Stack* newstack=createStack(k);
	cout<<"Input postfix expression"<<endl;
	string postfix;
	getline(cin, postfix);
	postCal(newstack,postfix );
	return 0;
}



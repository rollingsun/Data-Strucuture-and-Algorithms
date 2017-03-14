#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>


using namespace std;

struct Stack{
	int capacity;
	int top;
	char* array;
};

Stack* Createstack(){
	Stack* newstack=(Stack*)malloc(sizeof(Stack));
	cout<<"Input the size of your stack"<<endl;
	cin>>newstack->capacity;
	newstack->array=(char *)malloc(newstack->capacity*(sizeof(int)));
	newstack->top=-1;
	return newstack;
}

int isEmpty(Stack* stack){
	if(stack->top==-1){
		return 1;
	}
	return 0;
}

int isFull(Stack* stack){
	if(stack->top==stack->capacity-1){
		return 1;
	}
	return 0;
}

void push(Stack* stacktop,int data){	
	if(isFull(stacktop)){
		return ;
	}
	(stacktop->array[++stacktop->top])=data;
}	

char pop(Stack* stacktop){
	if (isEmpty(stacktop)){
		return 'X';
	}
	cout<<"popped from stack"<<stacktop->array[stacktop->top]<<endl;
	return(stacktop->array[stacktop->top--]);

}

int peek(Stack* stacktop){
	return(stacktop->array[stacktop->top]);
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
}


int main(){
	Stack* stack=Createstack();
	string infix;
	cin>>infix;
	string postfix;
	for(int i=0;i<infix.length();i++){
		char q=infix[i];
		int t=peek(stack);
		cout<<"peek value "<<t<<endl;
		if (isoperand(q)){
			postfix+=q;
			cout<<"postfix exp"<<postfix<<endl;
		}
		else if(q=='(')
			push(stack, q);
		else if(q==')'){	
			while(!isEmpty(stack) && peek(stack)!='('){
				postfix+=pop(stack);
				}
				cout<<"prefix till 0"<<postfix<<endl;
			pop(stack);
				cout<<"prefix till 1"<<postfix<<endl;
		}
		else {
			if (!isEmpty(stack) && precedence(q)<=peek(stack))
				postfix+=pop(stack);
			push(stack, q);	
		}
	}
	
	while(!isEmpty(stack))
        postfix+= pop(stack );	
cout<<infix<<endl;
cout<<postfix<<endl;
return 0;
}
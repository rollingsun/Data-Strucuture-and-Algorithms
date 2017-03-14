#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;

template<class vary>

class Stack
{
	int top;
	unsigned capacity;
	vary* array;
   
    public:
    	Stack(unsigned size)
{
    top=-1;
    capacity=size;
	array=(vary*)malloc(sizeof(vary));   
}

int isFull()
{
	return (top==capacity-1);
}


int isEmpty()
{
	return (top==-1);
}

void push(vary data)
{
   if(isFull())
   return;
   array[++top]=data;
   cout<<data<<"pushed to stack"<<endl;	
}

vary pop()
{
	if(isEmpty())
	return INT_MIN;
	else
		return array[top--];
}

vary peek()
{
	if(isEmpty())
	return INT_MIN;
	
	return array[top];
}
};

int main()
{
	
	Stack<int> stack(50);
	stack.push(3);
	stack.push(6);
	stack.push(10);
	cout<<stack.pop()<<endl;
	return 0;
	
	
	
}

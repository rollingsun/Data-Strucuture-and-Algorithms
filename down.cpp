	/*input

*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007

struct Stack
{
	ll top;
	ll *arr;
	ll capacity;
};
Stack *createstack()
{
	Stack *s = new Stack;
	s->top = -1;
	s->capacity=200;
	s->arr = new ll[200];
	return s;
}
bool isempty(Stack *s)
{
	if(s->top == -1)
		return 1;
	return 0;
}
bool isfull(Stack *s)
{
	if(s->top == s->capacity+1)
		return 1;
	return 0;
}
void push(Stack *s,ll key)
{
	if(!isfull(s))
	{
		s->arr[++s->top] = key;
	}
}
ll pop(Stack *s)
{
	if(!isempty(s))
	{
		return s->arr[s->top--];
	}
	return INF;
}
ll peek(Stack *s)
{
	if(!isempty(s))
		return s->arr[s->top];
	return INF;
}
void stackelements(Stack *s)
{
	if(!isempty(s))
	{
		ll temp = pop(s);
		cout<<temp<<" ";
		stackelements(s);
		push(s,temp);
	}
}
void insertatbottom(Stack *s,ll item)
{
	//cout<<"stack elements are now this"<<" ";
	//cout<<s->arr[s->top]<<" size of stack is"<<s->top<<endl;
	//debug(item);
	//cout<<endl;
	if(isempty(s))
	{
		//cout<<"item here"<<" "<<item<<endl;
		push(s,item);
	}
	else
	{
		ll temp = pop(s);
		//debug(temp);
		insertatbottom(s,item);
		push(s,temp);
	}
}
void reversestack(Stack *s)
{
	//cout<<"stack elements are now this"<<" ";
	//cout<<s->arr[s->top]<<endl;
	//cout<<endl;
	if(!isempty(s))
	{
		ll temp = pop(s);
		//debug(temp);
		reversestack(s);
		insertatbottom(s,temp);
		//cout<<"hello"<<endl;
	}
}
int main() 
{
	std::ios::sync_with_stdio(false);
	Stack *s = createstack();
	push(s,4);
	push(s,3);
	push(s,2);
	push(s,1);
	stackelements(s);
	cout<<endl;
	reversestack(s);
	stackelements(s);
	cout<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
void swap(char*a ,char* b){
	char temp;
	*a=temp;
	*a=*b;
	*b=temp;
}

int main(){
	int t;
	cin>>t;
	int temp=t;
	int s[10];
	int l=0;
	while(temp!=0){
		temp=temp/10;
		l++;
		}
	for(int j=l-1;j>=0;j--){
		s[j]=t%10;
		t=t/10;
	}
	int i;
	for (i = l-1; i >= 0; i--)
	{
		if(s[i-1]<=s[i])
			break;
	}
	cout<<s[i-1]<<endl;
	swap(&s[i-1],&s[l-1]);
	cout<<s[i-1]<<endl;	


return 0;
}
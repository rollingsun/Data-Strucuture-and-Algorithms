#include <iostream>
using namespace std;

int main(){
	int level,N;
	cin>>level;
	N=level;
	int count1;
	int count2=0;
	count1=1;
	for (int i = 1; i <=level; ++i)
	{
		/* code */
		count2=count2+2*i;
	}
	cout<<count2<<endl;
	int dash=0;
	for (int i = level; i>0; i--)
	{	
		dash=N-i;
		while(dash--){
			cout<<"-";
		}
		for (int j = 0; j < i; ++j)
		{
			cout<<count1<<"*";
			count1++;
		}
		count2=count2-i+1;
		for (int j = 1; j < i; ++j)
		{
			cout<<count2<<"*";
			count2++;
		}
		cout<<count2<<endl;
		count2=count2-i;
	}
return 0;
}
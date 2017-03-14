#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int T, M=0;
   cin>>T;
   cin>>M;
   int arr[M][M]={};
   int i=0;
   for(i=0;i<M;i++) {
   	int A,B=0;
   	cin>>A>>B;
   	arr[A][B]=1;
   	arr[B][A]=1;
   }
   
   int q=0;
   cin>>q;
   while (q--){
	int a,b
;	cin>>a>>b;
	if(arr[a][b]==1)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	
   }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	float a,b;
	int n;
	cin>>a>>b;;
	cin>>n;
	int i=0;
	float temp=100000;
	float d,e,v,c;
	for(i=0;i<n;i++){
		cin>>d>>e>>v;
		c=(sqrt((a-d)*(a-d)+(e-b)*(e-b)))/v;
		if(c<temp)
			temp=c;
	}

	cout<<temp<<endl;
	return 0;
}
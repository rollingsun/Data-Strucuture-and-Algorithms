#include <iostream>
using namespace std;

int count(int n){
	int c;

	while(n){
		n=n&(n-1);
		c++;
	}
	return c;
}

int main(){
	int T;
	cin >>T;
	while(T--){
		int v;
		cin>>v;
		int a=count(v);
		cout<<a<<endl;
	}

return 0;
}	
#include <iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	int d[N];
	for(int i=0;i<N;i++){
		cin>>d[i];
	}
	int sum=0;
	for(int i=0;i<N;i++){
		sum=sum+d[i];
	}
	sum=sum/2;
	if(sum==N-1){
		cout<<"Yes"<<endl
	}
	else
		cout<<"No"<<endl;
return 0;
}

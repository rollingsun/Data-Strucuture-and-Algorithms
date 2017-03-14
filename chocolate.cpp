#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	int i=0;
	
	while(T--){
	
			
		long long int arr[2];
		for (i=0;i<2;i++){
			cin>>arr[i];
		}

		if((arr[0]*arr[1])%2==0){
			cout<<"Yes"<<endl;
		}

		else{
			cout<<"No"<<endl;
		}
		
		}
	

}


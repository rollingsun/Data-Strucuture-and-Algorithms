#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int arr[N][4];
	int i,j=0;
	for(i=0;i<N;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];	
	}
	int query[M][2];
	for(i=0;i<M;i++){
		cin>>query[i][0]>>query[i][1];
	}	

	for(i=0;i<M;i++){
	int priority=0;
	int value;
		for(j=0;j<N;j++){
			if(query[i][0]==arr[j][0] && query[i][1]==arr[j][1])
				if(arr[j][3]>=priority){
					priority=arr[j][3];
					value=arr[j][2];
				}
		}
	cout<<value<<endl;
	}

return 0;	
}
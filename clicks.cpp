#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,K,a;
	cin>>N;
	cin>>K;
	int arr[N]={0};
	for (int i=0;i<K;i++){
		char clicks[10];
		scanf("%s",&clicks);
		int l =strlen(clicks);

		if(l==5){
			scanf("%d",&a);
			if(arr[a-1]==1)
				arr[a-1]=0;
			else
				arr[a-1]=1;
			
		}
		else {
			int k=0;
			memset(arr,0,sizeof(arr));
		}

		int count=0;
		for (int j = 0; j< N; ++j)
		{
			if(arr[j]==1)
				count++;
		}
		cout<<count<<endl;
	}

return 0;
}
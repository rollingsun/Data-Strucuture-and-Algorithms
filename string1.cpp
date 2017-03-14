#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T, N, M;
	cin>>T;

	while(T--){
		char str[10000];
		cin>>str;
		cin>>N>>M;
		sort(str+N,str+M+1);
		int k=M;
		int i=0;
		int j=N;
		char temp;
		while(j!=k){
			temp=str[j];
			str[j]=str[k];
			str[k]=temp;
			k--;	
			j++;
		}
		while(str[i])
		{	
			cout<<str[i];
			i++;
		}
	}

return 0;	
}		
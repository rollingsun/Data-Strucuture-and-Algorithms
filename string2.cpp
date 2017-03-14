#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	int T, N, M;
	cin>>T;

	while(T--){
		char str[10^6];
		cin>>str;
		int a,b,c,i =0;
		int length=sizeof(str);
		int subs=length*(length+1)/2;

		while(str[i]){
			if(str[i]=='a'){
				a=i+1;
				subs-=min(b,c);
			}
			else if(str[i]=='b'){
				b=i+1;
				subs-=min(a,c);
			}
			
			else(str[i]=='c'){
				c=i+1;
				subs-=min(b,a);
			}
			
			i++;
		}

		/*
		int j=0;
		char subs[2][10];
		cin>>subs[0]>>subs[1];
		for (int i = 0; i < 2; ++i)
		{
			j=0;
			while(subs[i][j])
			{
				cout<<subs[i][j];
				j++;
			}
			cout<<endl;
		}
	*/	
		vector<string> v;
		}

return 0;	
}		
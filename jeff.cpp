#include <iostream>
#include <string>

using namespace std;

int main(){
	string S;
	getline(cin, S);
	int N;
	cin>>N;
	while(N--){
		string inp;
		cin.ignore();
		getline(cin, inp);
		int len=inp.length();
		int c;
		int check=0;
		string read;
		for(int i=0;i<len;i++){
			c=0;
			for(int j=0;j<S.length();j++){
				if(inp[i]==S[j]){
					c++;
					break;
				}	
			}
			if(c==0){
				check++;
				break;
			}
		}
			if(check!=0){
				cout<<"No"<<endl;
			}
			else
				cout<<"Yes"<<endl;
	}
return 0;	
}
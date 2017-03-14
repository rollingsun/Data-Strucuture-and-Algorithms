#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
			char str[10000];
			cin>>str;
			int len=1;
			while(str[len]!='\0')
			{
				len++;
			}
			int j=len-1;
			int mid=len/2;
			int i=0;
			int costA, costB;
			int final=0;
			int flag=0;
			cin>>costA>>costB;
			while(i!=mid){
				if(str[i]=='a' && str[j]=='a'){
				
				}
				else if(str[i]=='b' && str[j]=='b'){
				}
				else if(str[i]=='/'){
					if(str[j]=='/'){
						str[j]=(costA>costB)?'b':'a';
						final=final+2*((costA>costB)?costB:costA);
						str[i]=str[j];
					}
					else
					{	
						if(str[j]=='a'){
							final=final+costA;
						}
						else{
							final=final+costB;
						}
						str[i]=str[j];
					}
				}
				else if (str[j]=='/'){
						if(str[i]=='a'){
							final=final+costA;
						}
						else{
							final=final+costB;
						}
						str[j]=str[i];
				}
				else{
					flag=1;
					break;
				}
				i++;
				j--;
			}
			if (flag==1)
			{
				cout<<"-1"<<endl;
			}
			else
				cout<<final<<endl;
		}
return 0;
}
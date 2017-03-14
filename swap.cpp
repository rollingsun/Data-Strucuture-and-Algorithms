#include <iost	ream>
#include <string>
using namespace std;

int main(){
	int k;
	cin>>k;
	string str;
	cin>>str;
	int len=str.size();
	int mid=(len%2==0)?(len/2-1):len/2;
	int i;
	int t,j;
	char temp;
	while(k--){
		i=1;
		while(i!=mid+1){
			temp=str[len-i];
			str[len-i]=str[i];
			t=i;
			while(t<(len-i-2)){
			str[t]=str[t+1];
				t++;
			}
			str[t]=temp;				
			i++;
		}
	}
	cout<<str<<endl;	
	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[10];
bool visited [10];

int main(){
	int a,b,i,x,y,j;
	cout<<"input node and edges"<<endl;
	cin>>a>>b;
	for(i=0;i<b;i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}

	for(i=1;i<=a;i++){
		cout<<"Adj list of node "<<i<<":";
		for(j=0;j<adj[i].size();j++){
			if(j==(adj[i].size()-1))
			{
				cout<<adj[i][j]<<endl;
				break;
			}
			else
				cout<<adj[i][j]<<"-->";
		}
	}
	return 0;
}
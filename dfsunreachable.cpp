#include <isotream>
#include <vector>
using namespace std;

vecotr<int>adj[10];
bool visited[10];

void dfs(s){
	visited[s]=true;
	int i=0;
	for(i=0;i<adj[s].size(),i++){
		if (adj[s][i]==false)
		dfs(i);
	}
}

void initialize(){
	for(int i=0;i<10;i++)
		visited[i]=false;
}

int main(){
	int a,b,i,x,y,j;
	cout<<"input node and edges"<<endl;
	cin>>a>>b;
	for(i=0;i<b;i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	
	initialize();

	for(j=0;j<a;j++){
		if(j!=t){
			dfs(j);
			count
	}
return 0;
}
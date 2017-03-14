#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[10];
int level[10];

void initialize(){
	for (int i = 0; i < 10; ++i)
		visited[i]=false;

}

void BFS(int s,bool visited[10], vector<int> v[10]){
	int l=0;
	queue<int> q;
	visited[s]==true;
	level[s]=l;
	q.push(s);
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(int i=0;i<v[p].size();i++){
			if(visited[v[p][i]]==false){
				level[v[p][i]]=level[l]+1;
				visited[i]=true;
				q.push(i);
			}
		}
		}

}

int main(){
	cout<<"Input nodes in graphs"<<endl;
	int N;
	cin>>N;
	int edges;
	cout<<"input the edges"<<endl;
	cin>>edges;
	vector<int> v[10];
	int level[10];
	int vis[10];
	int x,y;
	for(int i=0;i<edges;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	initialize();
	return 0;
}
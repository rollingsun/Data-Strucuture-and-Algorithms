#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
vector<int> sortMerge(vector<int> a, vector<int> b){
	vector<int> temp;
	int i=0,j=0;
	while(i<a.size() && j<b.size()){
		if(a[i]<=b[j]){
			temp.push_back(a[i]);
			i++;
		}
		else{
			temp.push_back(b[j]);
			j++;
		}
	}
	while(i<a.size()){
		temp.push_back(a[i]);
		i++;
	}
	while(j<b.size()){
		temp.push_back(b[j]);
		j++;
	}
	return temp;
}
vector<int> mergeSort(vector<int> &a,int f,int l){
	if(f==l){
		vector<int> temp;
		temp.push_back(a[f]);
		return temp;
	}
	int mid=(f+l)/2;
	return sortMerge(mergeSort(a,f,mid),mergeSort(a,mid+1,l));
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Array to be sorted: "; display(v);
	cout<<"Merge Sort: "; 
	display(mergeSort(v,0,n-1));
	return 0;
}

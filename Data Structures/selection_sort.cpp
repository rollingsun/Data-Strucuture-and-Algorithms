#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
void selectionSort(vector<int> a){
	int n=a.size();
	for(int i=0;i<n-1;i++){
		int minPos=i;
		for(int j=i+1;j<n;j++)
			if(a[minPos]>a[j])
				minPos=j;
		int temp=a[i];
		a[i]=a[minPos];
		a[minPos]=temp;
	}
	display(a);
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Array to be sorted: "; display(v);
	cout<<"Selection Sort: "; selectionSort(v);
	return 0;
}

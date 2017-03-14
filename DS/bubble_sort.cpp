#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
void bubbleSort(vector<int> a){
	int n=a.size();
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
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
	cout<<"Bubble Sort: "; 
	bubbleSort(v);
	return 0;
}


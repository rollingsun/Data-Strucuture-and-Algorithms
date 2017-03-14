#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
void insertionSort(vector<int> a){
	int n=a.size();
	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while(j>=0 && temp<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	display(a);
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Array to be sorted: "; 
	display(v);
	cout<<"Insertion Sort: ";
	 insertionSort(v);
	return 0;
}

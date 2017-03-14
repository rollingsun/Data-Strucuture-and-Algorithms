#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
int partition(vector<int>& A, int p,int q){
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++){
        if(A[j]<=x){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i],A[p]);
    return i;
}
void quickSort(vector<int>& A, int p,int q){
    int r;
    if(p<q){
        r=partition(A, p,q);
        quickSort(A,p,r);  
        quickSort(A,r+1,q);
    }
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Array to be sorted: "; display(v);
	cout<<"Quick Sort: "; 
	quickSort(v,0,n);	display(v);
	return 0;
}

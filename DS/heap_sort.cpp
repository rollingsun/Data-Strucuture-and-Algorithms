#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}
void maxHeapify(vector<int>& A, int i, int n){
	int largest;
	int l = 2 * i;
	int r = (2 * i) + 1;
	
	if ((l <= n) && (A[l - 1] > A[i - 1]))
	    largest = l;
	else
	    largest = i;
	
	if ((r <= n) && (A[r - 1] > A[largest - 1]))
	    largest = r;
	
	if (largest != i){
	    swap(A[i - 1], A[largest - 1]);
	    maxHeapify(A, largest, n);
	}
}

void buildMaxHeap(vector<int>& A, int n){
	for (int i = n / 2; i >= 1; i--){
	    maxHeapify(A, i, n);
	}
}

void heapSort(vector<int>& A, int n){
	buildMaxHeap(A, n);
	for (int i = n; i >= 1; i--) // Remove last element from heap
	{
	    swap(A[0], A[i]);
	    maxHeapify(A, 1, i); // Heapify reduced heap
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Array to be sorted: "; display(v);
	cout<<"Heap Sort: "; 
	heapSort(v,n-1);
	display(v);
	return 0;
}

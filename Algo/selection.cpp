#include<iostream>
using namespace std;

void swap(int* a, int* b){
	cout<<*a<<endl;
	int *temp=a;
	a=b;
	b=temp;
}
'''
void selection_sort(int *arr, int n){
	for (int i = 0; i < n; ++i)
	{	
		for (int j=i; j< n; ++j)
		{
			if(arr[j]<arr[i])		
			swap(arr[j], arr[i]);
		}
	
	}
}
'''
void Bubble(int* arr, int n){
	
	for (int j = 0; j < n; ++j)
	{
		bool swaped=false;
		for (int i = 0; i < n-1; ++i)
			{
				if(arr[i]>arr[i+1]){
					swap(arr[i], arr[i+1]);
					swaped=true;
				}
		}
		if (swaped==false)
			break;
	}
}
'''

void insertion(int* arr, int n){
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
'''
int main(){
	int a[]={22,4,66,192,23,56};
	int size=sizeof(a)/sizeof(int);
	Bubble(a, size);
	for (int i = 0; i < size; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}

#include<iostream>
using namespace std;

 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partitiona (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
 int partitiond(int arr[], int low, int high)
 {
 	int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
 	
 	
 	
 }

void quickSorta(int arr[], int low, int high)
{
    if (low < high)
    {
       
        int pia = partitiona(arr, low, high);
 
       
        quickSorta(arr, low, pia - 1);
        quickSorta(arr, pia + 1, high);
    }
}


void quickSortd(int arr[], int low, int high)
{
    if (low < high)
    {
       
        int pid = partitiond(arr, low, high);
 
       
        quickSortd(arr, low, pid - 1);
        quickSortd(arr, pid + 1, high);
    }
}


 
void quickSort(int arr[], int low, int high, char order)
{
	if(order=='a')
	{
		quickSorta(arr, low, high);
	}
	else if(order=='d')
	{
		quickSortd(arr, low, high);
	}
	
	
} 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
      cout<<arr[i]<<" ";
    cout<<
	endl;
}
 

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    char order;
  cout<<"enter order"<< endl;
    cin>>order;
    quickSort(arr, 0, n-1,order );
    cout<<"sorted array"<<endl;
    printArray(arr, n);
    return 0;
}

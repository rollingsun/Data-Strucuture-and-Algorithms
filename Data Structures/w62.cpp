#include<cstdio>
#include<cstdlib>
#define MOD 1000000007

int sequential_search (int* arr, int n, int find)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i]==find) {
			return i;
		}
	}
	return -1;
}

int binary_search (int* arr, int n, int find)
{	
	int beg=0,end=n-1,mid=(beg+end)/2;
	while(beg<=end)
	{
		if(arr[mid]==find) {
			return mid;
		}
		if(arr[mid]>find) {
			end=mid-1;
		}
		else {
			beg=mid+1;
		}
		mid=(beg+end)/2;
	}
	return -1;
}

int indexed_sequential_search (int* arr, int n, int find)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i]==find) {
			return i;
		}
	}
	return -1;
}

int main()
{
	int n,x,pos;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("Enter elements (all distinct and sorted): ");
	int* arr=(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}
	
	printf("Sequential Search: \n");
	printf("Enter element to find: ");
	scanf("%d",&x);
	pos=sequential_search(arr,n,x);
	if(pos==-1) printf("Not found\n");
	else printf("Element found at position: %d\n",pos+1);
	
	printf("Binary Search: \n");
	printf("Enter element to find: ");
	scanf("%d",&x);
	pos=binary_search(arr,n,x);
	if(pos==-1) printf("Not found\n");
	else printf("Element found at position: %d\n",pos+1);
	
	printf("Indexed Sequential Search: \n");
	printf("Enter element to find: ");
	scanf("%d",&x);
	pos=indexed_sequential_search(arr,n,x);
	if(pos==-1) printf("Not found\n");
	else printf("Element found at position: %d\n",pos+1);
	
	return 0;
}

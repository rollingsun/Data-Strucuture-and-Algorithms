/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory for result array, and fill result's length in length_of_array
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>	
using namespace std;

int* plusOne(int* A, int n1, int *length_of_array) {
	// SAMPLE CODE
	int i=*length_of_array-1,j;
	if(A[i]!=9 && A[0]!=0){
	    A[i]=A[i]+1;
	    return A;
	}
	if(i==0 && A[i]==0){
        A[i]=A[i]+1;
	    return A;
	}
	if(A[0]==0 && A[i]!=9){
	    int *result=(int* )malloc(sizeof(int)*(i-1));
	    for(j=0;j<i;j++){
	        result[j]=A[j+1];
	    }
	return result;
	}
	j=i;
	if(A[i]=9){
		while(A[j]==9){
			A[j]=0;
			if(j==0)
				break;
			j--;
		}
		if(j==0){
			int *result=(int* )malloc(sizeof(int)*(i));				
			result[0]=1;
			for (j = 1; j <i ; ++j)
			{
				result[j]=0;
			}
			return result;
		}
		
		else if(A[0]==0 && j!=0){
			int *result=(int* )malloc(sizeof(int)*(i-1));				
			A[j]=A[j]+1;
			for (j = 0; j <i ; ++j){
				/* code */
				result[j]=A[j+1];
			}
			return result;
		}
		else {
			A[j]=A[j]+1;
			cout<<"j is "<<j<<" A[j] is "<<A[j]<<endl;
			if(A[0]==0){
				int *result=(int* )malloc(sizeof(int)*(i));				
				for (j=0;j<=i-1; j++)
				{
					cout<<"j is "<<j<<" A[j] is "<<A[j]<<endl;

					result[j]=A[j+1];
				}
				return result;
			}
			else{
				cout<<"i is "<<i<<endl;
				int *result=(int* )malloc(sizeof(int)*(i));				
				for (j=0;j<=i; j++)
				{
					result[j]=A[j];
				}
				return result;
			}
		}
        
}
}

int main(){
	int a[9]={ 2, 5, 6, 8, 6, 1, 2, 4, 5};
	int len=sizeof(a)/sizeof(int);
	int *rs=(int*)malloc(sizeof(int)*len);
	rs=plusOne(a, 1, &len);
	for (int i = 0; i <9; ++i)
	{
		printf("%d\n ",rs[i]);
	}
	printf("%d\n",len);
	return 0;
}
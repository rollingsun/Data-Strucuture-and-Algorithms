#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int** diagonal(){
	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int s=sizeof(a)/sizeof(a[0]);
	printf("%d\n", s);
	int ** arr=(int** )malloc(sizeof(int*)*2*s);
	int i=0;
	for (  i= 0; i < s; ++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*(i+1));
		}
	for (i;i <s; ++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*(i+1));
		}
	for (i;i <2*s-1; ++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*(2*s-i-1));
		}
		
	int j,k;
		int r=0;
		int c=0;
	for (i = 0; i <s; ++i)
	{
		j=0;
		r=0;
		c=i;
		for (j=0; j <=i; j++)
		{
			cout<<"i is "<<i<<" j is "<<j<<" r is "<<r<<" k is "<<k<<" a[r][c] is "<<a[r][c]<<endl;
			arr[i][j]=a[r][c];
			r++;
			c--;
		}
	}
	for (i; i <2*s; i++)
	{
		r=i-s+1	;
		c=s-1;
		j=2*s-i-1;
		while(j>0)
			{
			cout<<"i is "<<i<<" j is "<<j<<" r is "<<r<<" c is  "<<c<<" a[r][c] is "<<a[r][c]<<endl;
			arr[i][j]=a[r][c];
			r++;
			c--;
			j--;
		}

	}

		
/*
	for (int t = 0; t < s; ++t)
	{	
		for (int l = 0; l < s; ++l)
		{
			printf("%d\n ",arr[t][l] );	
		}
	}
*/
	return arr;
}


int main(){
	int** a=(int** )malloc(sizeof(int*));
	int i=0;
	for (  i= 0; i < s; ++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*(i+1));
		}
	for (i;i <s; ++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*(i+1));
		}


}
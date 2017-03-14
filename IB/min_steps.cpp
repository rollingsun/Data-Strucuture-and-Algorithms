#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>	
#include <vector>
using namespace std;

void minDistance(int r, int c, int A[][2]){
	/*
	cout<<"A ka size "<<sizeof(A[0])<<endl;
	int nrows=sizeof(A)/sizeof(int);
	int ncols=sizeof(A[0])/sizeof(A[0][0]);
	int min,len=0;
	cout<<"nrows "<<nrows<<" ncols is "<<ncols<<endl;
	for (int i = 0; i <nrows; i++){
		min=fmin(abs(A[i][0]-A[i+1][0]), abs(A[i][1]-A[i+1][1]));
		cout<<"min is "<<min<<endl;
		len=abs(fmax(A[0][i+1],A[1][i+1])-min)+min;
		cout<<"length is "<<len<<endl;
	}
	*/
	int e=0,dis;
	if(n1==1)
		
	for (int i = 0; i < r-1; ++i)
	{
		dis=0;
		dis=fmax(abs(A[i][0]-A[i+1][0]), abs(A[i][1]-A[i+1][0]));
		e=e+dis;
	}
	cout<<e<<endl;
}

int main(){

	int a[3][2]={{1,1},{4,1},{3,2}};
	int nrows=sizeof(a)/sizeof(a[0]);
	int ncols=sizeof(a[0])/sizeof(int);	
	minDistance(nrows,ncols, a);
	return 0;
}


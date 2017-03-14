#include <stdio.h>
#include <stdlib.h>
using namespace std;

int** spiral2(int n){
	int top=0,left=0;
	int bottom=n-1,right=n-1;
	int **arr = (int **)malloc(n * sizeof(int *));
    for (int i=0; i<n; i++)
         arr[i] = (int *)malloc(n * sizeof(int));
     int count=1;
	while(true){
		if(top>bottom && left>right)
			break;
		for (int i =left; i <=right ; ++i)
		{
				arr[top][i]=count;
				count++;
		}
		top++;
		if(top>bottom && left>right)
			break;
		for (int i =top; i <=bottom ; i++)
		{
				arr[i][right]=count;
				count++;
		}
		right--;
		if(top>bottom && left>right)
			break;
		for (int i =right; i >=left ; i--)
		{
				arr[bottom][i]=count;
				count++;
		}
		bottom--;
		if(top>bottom && left>right)
			break;
		for (int i =bottom; i >=top ; --i)
		{
				arr[i][left]=count;
				count++;
		}
		left++;
	}	
	
	return arr;
}


int main(){
	int** arr;
	arr=spiral2(80);
	int i=1	;
		for (int j= 0; j< 80; ++j)
	
		{
			printf("%d\n ", arr[i][j]);
		}

}
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int n=2;
	int top=0,left=0;
	int bottom=n-1,right=n-1;
	int **arr;
	arr=(int** )malloc(sizeof(int*)*bottom);
	arr[0]=(int* )malloc(sizeof(int)*right*bottom);
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
		for (int i =top; i <=bottom ; ++i)
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

	for (int i = 0; i < n; ++i)
		for (int j= 0; j< n; ++j)

		{
			printf("%d\n ", arr[i][j]);
		}
	return 0;
}

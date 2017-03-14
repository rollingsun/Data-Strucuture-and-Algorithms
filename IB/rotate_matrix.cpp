#include <iostream>

using namespace std;

int main(){
	int A[3][3]={1,2,3,4,5,6,7,8,9};
	int temp;
    int rows=3,cols=3;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols/2;j++){
            if(i!=j){
                temp=A[i][j];
                A[i][j]=A[j][i];
                A[j][i]=temp;
            }
        }
    }

       for(int i=0;i<rows/2;i++){
        for(int j=0;j<cols;j++){
                temp=A[j][i];
                A[j][i]=A[rows-1-j][i];
                A[rows-1-j][i]=temp;
            
        }
    }

    int j;
    for (int i = 0; i < rows; ++i)
    {
    	for (j = 0; j < rows; ++j)
    	{
    		cout<<A[i][j]<<" ";
    	}
    	cout<<""<<endl;
    }
	return 0;    
    
}

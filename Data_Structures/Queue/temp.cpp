#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int* array[3];
	for (int i = 0; i <3; ++i)
	{
		array[i]=(int* )malloc(sizeof(int));
	}
	array[2][3]=3;
	cout<<" asdfafa "<<array[2][3]<<endl;;
}
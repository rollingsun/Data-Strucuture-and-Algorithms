#include <iostream>
#include <stdlib.h>

using namespace std;

struct queue
{
	int enqueueto;
	int dequeuefrom;
	int capacity;
	int *array=(int *)malloc(capacity*(sizeof(array)));
};

int Createqueue(queue* Q){
	cout<<"Enter the capacity "<<endl;
	queue *Q=malloc(sizeof(queue));
	cin>>Q->capacity;
	Q->enqueueto=(enqueueto%capacity)+1;
	dequeueto=(dequeueto%capacity)+1;

}
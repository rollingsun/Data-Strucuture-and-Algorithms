#include <stdio.h>
#include <iostream>
using namespace std;

int maxSubArray(const int* A, int n1) {
    int front=0;
    int i,k;
    int back=0;
    int ans,sum;
    int min=-11111;
    while(front<n1){
        sum=0;
        while(back<n1){
            sum=sum+A[back];
            back++;
            if(sum>min){
                ans=sum;
            }
            /*if(sum>min){
                int *temp=int*(malloc((back-front)*sizeof(int)))
                for(i=front;i<back;k=0;k++;i++){
                    temp[k]=A[i];
                }
            }
            */
        }
        front++;
    }
}

int main()
{
	int a[3][3]=	{1,2,3,4,5,6,7,8,9};
	int limit=5;
	int t,b,l,r;
	t=0;l=0;
	b=0	;r=0;
	cout<<"t is "<<l<<endl;
	while(true)
	{
		//top
		if(l<=r && t<=b){
			for (int i = l; i <=r; i++){
			//cout<<"I is "<<i<<"and t is "<<t<<endl;
				cout<<a[t][i]<<endl;
			}
		t++;
		}
		else 
			break;
		if(l<=r && t<=b){
		for (int i = t; i <=b; i++){
			cout<<a[i][r]<<endl;
		}
		r--;
		}
		else
			break;
		//bottom
		if(l<=r && t<=b){
		for (int i = r; i>=l;i--){
			cout<<a[b][i]<<endl;
		}
		b--;
		}
		else 
			break;
		//left
		if(l<=r && t<=b){
		for (int i = b; i >=t; i--){
			cout<<a[i][l]<<endl;
		}
		l++;
		}
		else
		break;	
	}
	return 0;
}
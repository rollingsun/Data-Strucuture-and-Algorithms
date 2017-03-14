#include <stdio.h>
#include <iostream>
 using namespace std;

void towerOfHanoi(int n, char initial, char destination, char auxRod)
{
    if (n == 1)
    {
        cout<<"Move disk 1 from rod "<<initial<<"to rod "<<destination<<endl;
        return;
    }
    towerOfHanoi(n-1, initial, auxRod, destination);
    cout<<"Move disk"<<n<<"from rod "<<initial<<" to rod "<<destination<<endl;
    towerOfHanoi(n-1, auxRod, destination, initial);
}
 
int main()
{   
    int n;
    cout<<"Input the number of disks "<<endl;
    cin>>n; 
    towerOfHanoi(n, 'A', 'C', 'B');  
    return 0;
}

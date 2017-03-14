#include <iostream>
using namespace std;

void bss(int a){
	cout<<"a is "<<a<<endl;
}
void bss(char a){
	cout<<"a is "<<a<<endl;
}
int main(){
	bss('4');
	bss(5);
return 0;
}
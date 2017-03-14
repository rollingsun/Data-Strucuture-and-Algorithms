#include<stdio.h>
#include<string.h>

int main(){

	int flag=1;
	int out=1;
	char inp[100];
	
	while(flag==1){


	scanf("%s", inp);
	int i,j,len_str;

	len_str=strlen(inp);

	int conv[100];

/*
	for(i=0;i<len_str;i++){
		conv[i]=inp[i];
	}

*/
	for (i=0;i<len_str;i++){
		for (j=i+1;j<len_str;j++){
			
			if(inp[i]==inp[j] || (inp[i]<='a' && inp[i]>='z' || inp[i]<='A' && inp[i]>='Z' || inp[i]<='0' && inp[i]>='9' )) {
				flag=1;
				out=0;
				break;
			}
			
			else{
				flag=0;
				}
			}

			if(flag==1){
				break;
			}

			}

		if (flag==1){
				printf("Invalid");
				break;
			}

		else{
			printf("Valid");
			break;
		}	
	

	}


	
return 0;
}
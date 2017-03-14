#include <bits/stdc++.h>
#include <stdio.h>

 
int main(){
 int i=0;

 int T;
 scanf("%d", &T);


while(T--){
	float countM=0;
	float countF=0;

	int N;
 	scanf("%d", &N);

	long long int s[2];

	for (i=0;i<2;i++){
		scanf("%lld", s+i);
	}

	long long int c[N];

	for (i=0;i<N;i++){
		scanf("%lld", c+i);
	}


	for (i=0;i<N;i++){	
		if(c[i]%s[0]==0 && c[i]!=0){
			countM++;
		}

		else if(c[i]%s[1]==0 && c[i]!=0){
			countF++;
		}

	}

	float t= ((countM+countF)/float(N))*100;

	if(t>=70){
		printf("Yes\n");
		if(countF>countM){
			printf("Fultan\n");
		}
		else if (countM>countF){
			printf("Multan\n");
		}

		else{
			printf("Both \n");
		}
	}

	else{
		printf("No\n"); 
	}
}

return 0;
}


#include<stdio.h>
int fact(int n){
	if(n==0||n==1) return 1;
	return n*fact(n-1);
}
int main(){
	int n;
	while(1){
		printf("Enter a number:");
		if(scanf("%d",&n))
		printf("%d!=%d\n",n,fact(n));
		else{
			printf("program terminated..");
			return 0;
		}
	}
}

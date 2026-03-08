#include<stdio.h>
int fibo(int n){
	if(n==0)return 0;
	if(n==1||n==2)return 1;
	return fibo(n-1)+fibo(n-2);
}
int main(){
	int n,i;
	while(1){
		printf("\nEnter no of terms:");
		if(scanf("%d",&n))
		for(i=0;i<n;i++)
		printf("%d\t",fibo(i));
		else{
			printf("Program terminated!!\n");
			return 0;
		}
	}
}

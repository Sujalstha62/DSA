#include<stdio.h>
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	int a,b;
	while(1){
		printf("Enter two numbers:");
		if(scanf("%d%d",&a,&b))
		printf("GCD=%d\n",gcd(a,b));
		else{
			printf("Porgram terminated...");
			return 0;
		}
	}
}

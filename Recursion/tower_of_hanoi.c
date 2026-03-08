#include<stdio.h>
void tower(int n, char A,char B,char C){
	if(n==1){
		printf("Move 1 from %c to %c\n",A,C);
		return;
	}
	tower(n-1,A,C,B);
	printf("Move %d from %c to %c\n",n,A,C);
	tower(n-1,B,A,C);
}
int main(){
	int n;
	char A,B,C;
	while(1){
		A='A';
		B='B';
		C='C';
		printf("Enter N:");
		if(scanf("%d",&n))tower(n,A,B,C);
		else break;
	}
	printf("Program terminated...");
	return 0;
}


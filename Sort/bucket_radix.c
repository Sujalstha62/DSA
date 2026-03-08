#include<stdio.h>
#define N 30
void sort(int a[],int b[],int div,int n){
	int i,j,c=0;
	for(i=0;i<=9;i++){
		for(j=0;j<n;j++){
			if((a[j]/div)%10==i){
				b[c]=a[j];
				c++;
			}
		}
	}
}
void bucket(int a[],int b[],int n){
	int i,j,max=0,temp,d=0,div=1;
	for(i=0;i<n;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	while(max!=0){
		max=max/10;
		d++;
	}
	for(i=0;i<d;i++){
		sort(a,b,div,n);
		div*=10;
		for (j = 0; j < n; j++) {
	        temp = a[j];
	        a[j] = b[j];
	        b[j]= temp;
    	}
	}
}
int  main(){
	int i,n,a[N],b[N];
	printf("Enter no. of terms:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	bucket(a,b,n);
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}

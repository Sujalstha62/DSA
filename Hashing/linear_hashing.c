#include<stdio.h>
#define max 20
int main(){
	int n,i,hash,count=0,hash_key,arr[max];
	printf("Enter the number of available location:");
	scanf("%d",&n);
	for(i=0;i<max;i++) arr[i]=-1;
	printf("Enter numbers:");
	while(count<n){
		if(!scanf("%d",&hash))break;
		hash_key=hash%n;
		i=0;
		while(arr[hash_key]!=-1){
			hash_key=(hash+i)%n;
			i++;
		}
		arr[hash_key]=hash;
		count++;
	}
	for(i=0;i<n;i++) printf("%d\t",arr[i]);
}

#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
int main(){
	int n,i,hash,count=0,hash_key,hash_ke;
	cout<<"Enter the number of available location:";
	cin>>n;
	vector<int> arr(n,-1);
	while(count<n){
		cout<<"Enter number:";
		cin>>hash;
		if(cin.fail()){
			break;
		}
		hash_ke=hash%n;
		hash_key=hash_ke;
		i=1;
		while(arr[hash_key]!=-1){
			hash_key=(hash_ke+i*(hash_ke+i-1))%n;
			i++;
		}
		arr[hash_key]=hash;
		count++;
	}
	cout<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}

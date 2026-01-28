#include<iostream>
#include<cctype>
using namespace std;
int fact(int n){
	if(n==0||n==1){
		return 1;
	}
	return n*fact(n-1);
}
int main(){
	int n;
	while(true){
		cout<<"Enter a number:";
		cin>>n;
		if(!cin.fail())
		cout<<n<<"!="<<fact(n)<<endl;
		else{
			cout<<"Program terminated..";
			return 0;
		}
	}
}

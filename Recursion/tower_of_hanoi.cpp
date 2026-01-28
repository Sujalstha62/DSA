#include<iostream>
#include<cctype>
using namespace std;
void tower(int n, char A,char B,char C){
	if(n==1){
		cout<<"Move 1 from "<<A<<" to "<<C<<endl;
		return;
	}
	tower(n-1,A,C,B);
	cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
	tower(n-1,B,A,C);
}
int main(){
	int n;
	char A,B,C;
	while(true){
		A='A';
		B='B';
		C='C';
		cout<<"Enter N:";
		cin>>n;
		if(!cin.fail())tower(n,A,B,C);
		else break;
	}
	cout<<"Program terminated...";
	return 0;
}


#include<iostream>
#include<string>
using namespace std;
#define max 20
class stack{	
    char st[max];
    int topp;	
public:
	stack(){
		topp=-1;
	}
    void push(int value) {
            st[++topp] = value;
    }
    void pop() {
            topp--;
    }
    int top() {
        return st[topp];
    }
    bool empty(){
    	return (topp==-1);
	}
};
int priority(char op){
	if(op=='$')return 3;
	if(op=='/' || op=='*')return 1;
	if(op=='-' || op=='+')return 0;
}
bool isop(char op){
	return (op=='+'||op=='-'||op=='*'||op=='/'||op=='$');
}
string intopost(string ch){
	stack st;
	string post="";
	int c=0;
	for(int i=0;i<ch.length();i++){
		if(isalnum(ch[i])){
			post+=ch[i];
		}
		else if(ch[i]=='('){
			st.push('(');
		}
		else if(ch[i]==')'){
			while(!st.empty() && st.top()!='('){
				post += st.top();
				st.pop();
			}
			if(!st.empty()) st.pop();
		}
		else if(isop(ch[i])){
			while(!st.empty() && st.top()!='(' && priority(st.top())>=priority(ch[i])){
				post+=st.top();
				st.pop();
			}
			st.push(ch[i]);
		}
	}
	while(!st.empty()){
		post+=st.top();
		st.pop();
	}
	return post;
}
string intopre(string ch){
	stack st;
	string pre="";
	int c=0;
	for(int i=0;i<ch.length();i++){
		if(isalnum(ch[i])){
			pre+=ch[i];
		}
		else if(ch[i]==')'){
			st.push(')');
		}
		else if(ch[i]=='('){
			while(!st.empty() && st.top()!=')'){
				pre+= st.top();
				st.pop();
			}
			if(!st.empty()) st.pop();
		}
		else if(isop(ch[i])){
			while(!st.empty() && st.top()!=')' && priority(st.top())>=priority(ch[i])){
				pre+=st.top();
				st.pop();
			}
			st.push(ch[i]);
		}
	}
	while(!st.empty()){
		pre+=st.top();
		st.pop();
	}
	return pre;
}
string strrev(string A){
	for(int i=0;i<A.length()/2;i++){
		char t=A[i];
		A[i]=A[A.length()-i-1];
		A[A.length()-i-1]=t;
	}
	return A;
}
int main(){
	string expression,temp;
	int choice;
	while(true){
		cout<<"1.Postfix\n2.Prefix\nEnter your choice:";
		cin>>choice;
		cout<<"Enter an operation:";
		cin>>expression;
			switch(choice){
				case 1:
					cout<<intopost(expression)<<endl;
					break;
				case 2:
					cout<<strrev(intopre(strrev(expression)))<<endl;
					break;
				default:
					cout<<"Invalid input";
					return 1;
			}
		}
}

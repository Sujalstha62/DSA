#include<iostream>
#include<string>
#include<cctype>
#include<math.h>
#define max 20
using namespace std;
bool isop(char op){
	return (op=='+'||op=='-'||op=='*'||op=='/'||op=='$');
}
class stack{	
    double st[max];
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
    void clear(){
    	topp=-1;
	}
};
class expression{
	string exp;
	stack st;
	double result,op1,op2;
	public:
		expression(){result=0;exp="";	}
		expression(string e){result=0;exp=e;}
		void evalupost(){
			if(exp=="")cout<<"Invalid input!!";
			else{
				if(isop(exp[0])){
						cout<<"prefix expression detected!!";
						return;
				}
				for(int i=0;i<exp.length();i++){
					if(isdigit(exp[i])){
						st.push(exp[i]-'0');
					}
					else if(isop(exp[i])){
						int op2=st.top();st.pop();
						int op1=st.top();st.pop();
						switch (exp[i]) {
                    	case '+': result = op1 + op2; break;
                    	case '-': result = op1 - op2; break;
                    	case '*': result = op1 * op2; break;
                    	case '/': result = op1 / op2; break;
                    	case '$': result = pow(op1, op2); break;
                	}
						st.push(result);
					}
					else{
						cout<<"Invaid input.... Program terminated!!";
						return;
					}
				}
			}
		}
		void evalupre(){
			if(exp=="")cout<<"Invalid input!!";
			else{
				if(isop(exp[exp.length()-1])){
						cout<<"postfix expression detected!!";
						return;
					}
				for(int i=exp.length()-1;i>=0;i--){
					
					if(isdigit(exp[i])){
						st.push(exp[i]-'0');
					}
					else if(isop(exp[i])){
						int op1=st.top();st.pop();
						int op2=st.top();st.pop();
						switch (exp[i]) {
                    	case '+': result = op1 + op2; break;
                    	case '-': result = op1 - op2; break;
                    	case '*': result = op1 * op2; break;
                    	case '/': result = op1 / op2; break;
                    	case '$': result = pow(op1, op2); break;
                	}
						st.push(result);
					}
					else{
						cout<<"Invaid input.... Program terminated!!";
						return;
					}
				}
			}
		}
		void show(){
			cout<<"Result="<<result<<"\n\n";
		}
	};
int main(){
	string exp;
	int choice;
	while(true){
		cout<<"1.postfix\n2.prefix\nEnter your choice:";
		cin>>choice;
		cout<<"Enter an expression:";
		cin>>exp;
		expression A(exp);
		switch(choice){
			case 1:
				A.evalupost();
				A.show();
				break;
			case 2:
				A.evalupre();
				A.show();
				break;
			default:
				cout<<"Invalid Input program terminated:";
				return 0;
		}
	}
	return 0;
}

// http://geeksquiz.com/stack-set-2-infix-to-postfix/

#include <iostream>
#include <stack>
using namespace std;

int preced(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

bool isOperand(char ch){
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

string infixToPostfix(string exp){
	stack<char> s;
	string res="";
	for(int i=0; i<exp.length(); i++){
		if(isOperand(exp[i])){
			res = res + exp[i];
		}
		else if(exp[i] == '('){
			int tmp = i;
			while(exp[i] != ')'){
				i++;
			}
//			i++;
			res = res + infixToPostfix(exp.substr(tmp+1, i-tmp-2));
		}
		else {
			if(s.empty()){
				s.push(exp[i]);
			}
			else if(preced(s.top()) <= preced(exp[i])){
				s.push(exp[i]);
			}
			else {
				while(!s.empty()){
					res = res + s.top();
					s.pop();
				}
				s.push(exp[i]);
			}
		}
	}
	while(!s.empty()){
		res = res + s.top();
		s.pop();
	}
	return res;
}

int main(){
	string exp= "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(exp);
    return 0;
}


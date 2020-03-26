// http://geeksquiz.com/stack-set-4-evaluation-postfix-expression/

#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

bool isInt(char ch){
	return (ch >= '0' && ch <= '9');
}

int eval(int a, int b, char op){
	if(op == '+')
		return a+b;
	else if(op == '-')
		return a-b;
	else if(op == '*')
		return a*b;
	else if(op == '/')
		return a/b;
	else if(op == '^')
		return pow(a, b);
}

int evaluatePostfix(char *exp){
	stack<int> s;
	char zero = '0';
	int i=0;
	for(; exp[i]; i++){
		if(isInt(exp[i])){
			s.push(int(exp[i])-zero);
		}
		else {
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			s.push(eval(a, b, exp[i]));
		}
	}
	return s.top();
}

int main(){
	char exp[] = "231*+9-";
 	printf ("Value of %s is %d", exp, evaluatePostfix(exp));
	return 0;
}


// http://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

#include <iostream>
#include <stack>
using namespace std;

char para(char p){
	if(p == ')')
		return '(';
	else if(p == ']')
		return '[';
	else if(p == '}')
		return '{';
}

void checkPara(string str){
	stack<char> s;
	for(int i=0; i<str.length(); i++){
		if(str[i] == '{' || str[i] == '[' || str[i] == '('){
			s.push(str[i]);
		}
		else {
			if(s.empty()){
				cout<<"err";
				return;
			}
			if(para(str[i]) == s.top()){
				s.pop();
			}
			else{
				cout<<"err";
				return;
			}
		}
	}
	if(s.empty())
		cout<<"perfect";
	else
		cout<<"err1";
}

int main(){
	string str = "[()]{}{[()()]()}";
	checkPara(str);
	return 0;
}


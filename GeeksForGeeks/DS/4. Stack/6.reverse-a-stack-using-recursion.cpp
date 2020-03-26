// http://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int t){
	if(s.empty()){
		s.push(t);
	}
	else {
		int tmp = s.top();	s.pop();
		insertAtBottom(s, t);
		s.push(tmp);
	}
}

void reverse(stack<int> &s){
	if(s.empty())
		return;
	int tmp = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s, tmp);
}

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	reverse(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}


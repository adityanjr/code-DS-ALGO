// http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure

#include <iostream>
#include <stack>
using namespace std;

struct Min {
	int data;
	int ind;
};

class specialStack {
	stack<int> s;
	stack<Min*> sm;
	public:
		specialStack();
		void push(int);
		int getMin();
		int pop();
};

specialStack::specialStack(){
}

void specialStack::push(int data){
	s.push(data);
	if(sm.empty()){
		Min *tmp = new Min;
		tmp->data = data;
		tmp->ind = 0;
		sm.push(tmp);
	}
	else {
		Min *t = sm.top();
		if(t->data < data){
			sm.top()->ind++;
		}
		else {
			Min *tmp = new Min;
			tmp->data = data;
			tmp->ind = s.size()-1;
			sm.push(tmp);
		}
	}
}

int specialStack::getMin(){
	if(s.empty())
		return -1;
	else
		return sm.top()->data;
}

int specialStack::pop(){
	if(s.empty())
		return -1;
	int res = s.top();
	s.pop();
	if(sm.top()->data == res){
		sm.pop();
	}
	else {
		sm.top()->ind--;
	}
}

int main(){
	specialStack s;
    s.push(20);
    s.push(10);
    s.push(30);
    cout<<s.getMin()<<endl;
    s.push(5);
    cout<<s.getMin()<<'\n';
    s.pop();
    cout<<s.getMin()<<'\n';
    s.pop();
    cout<<s.getMin()<<'\n';
    s.pop();
    cout<<s.getMin()<<'\n';
	return 0;
}


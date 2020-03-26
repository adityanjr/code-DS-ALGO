// http://www.geeksforgeeks.org/implement-two-stacks-in-an-array/

#include <iostream>
using namespace std;

class twoStacks{
	int *arr;
	int size;
	int top1, top2;
public:
	twoStacks(int n){
		size = n;
		top1 = -1;
		top2 = n;
		arr = new int[n];
	}
	void push1(int x);
	void push2(int x);
	int pop1();
	int pop2();
};

void twoStacks::push1(int x){
	if(top2-top1 == 1){
		cout<<"OverFlow";
		return;
	}
	top1++;
	arr[top1] = x;
}

void twoStacks::push2(int x){
	if(top2-top1 == 1){
		cout<<"OverFlow";
		return;
	}
	top2--;
	arr[top2] = x;
}

int twoStacks::pop1(){
	if(top1==-1){
		cout<<"empty";
		return -1;
	}
	top1--;
	return arr[top1+1];
}

int twoStacks::pop2(){
	if(top2==-1){
		cout<<"empty";
		return -1;
	}
	top2--;
	return arr[top2+1];
}

int main(){
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}

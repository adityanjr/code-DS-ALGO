// http://www.geeksforgeeks.org/next-greater-element

#include <iostream>
#include <stack>
using namespace std;

void printNGE(int *a, int n){
	stack<int> s;
	s.push(a[0]);
	for(int i=1; i<n; i++){
		while(!s.empty() && s.top() < a[i]){
			int tmp = s.top(); s.pop();
			cout<<tmp<<"-->"<<a[i]<<"\n";
		}
		s.push(a[i]);
	}
	while(!s.empty()){
		int tmp = s.top(); s.pop();
		cout<<tmp<<"-->"<<-1<<"\n";
	}
}

int main(){
	int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
	return 0;
}


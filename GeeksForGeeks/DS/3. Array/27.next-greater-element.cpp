// http://www.geeksforgeeks.org/next-greater-element

#include <iostream>
#include <stack>
#include "array.h"

void printNGE(int *a, int n){
	stack<int> s;
	s.push(a[0]);
	for(int i=1; i<n; i++){
		while(!s.empty()){
			int t = s.top();
			if(t < a[i]){
				cout<<t<<"-->"<<a[i]<<'\n';
				s.pop();
			}
			else {
				break;
			}
		}
		s.push(a[i]);		
	}
	while(!s.empty()){
		int t = s.top();
		cout<<t<<"-->"<<-1<<'\n';
		s.pop();
	}
}

int main(){
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    getchar();
    return 0;
}

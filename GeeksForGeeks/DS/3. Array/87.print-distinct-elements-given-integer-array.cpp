// http://geeksquiz.com/print-distinct-elements-given-integer-array/

#include <iostream>
#include <set>
#include "array.h"

void printDistinct(int *a, int n){
	set<int> s;
	set<int>::iterator it;
	for(int i=0; i<n; i++)
		s.insert(a[i]);
	for (it=s.begin(); it!=s.end(); ++it){
    	cout <<*it<<" ";
	}
  std::cout << '\n';
}

int main(){
	int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    printDistinct(arr, n);
	return 0;
}


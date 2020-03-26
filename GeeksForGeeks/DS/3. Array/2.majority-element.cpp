// http://www.geeksforgeeks.org/majority-element

#include <iostream>
#include "array.h"

int elect(int *a, int n){
	int maj = 0, count = 1;
	for(int i=1; i<n; i++){
		if(a[maj] == a[i])
  		    count++;
		else
			count--;
		if(count == 0){
			maj = i;
			count = 1;
		}
	}
	return a[maj];
}

bool isMajor(int *a, int n, int maj){
	int count = 0;
	for(int i=0; i<n; i++){
		if(maj == a[i])
			   count++;
	}
	if(count > n/2)
			 return true;
    return false;
}

void printMajority(int *a, int n){
	int maj = elect(a, n);
	if(isMajor(a, n, maj))
	    cout<<maj;
	else
		cout<<"No maj";
}

int main() {
    int a[] = {1, 3, 3, 1, 2, 1};
    printMajority(a, 7);
    return 0;
}

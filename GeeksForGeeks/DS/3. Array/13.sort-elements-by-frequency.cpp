// http://www.geeksforgeeks.org/sort-elements-by-frequency

#include <iostream>
#include <algorithm>
#include <vector>
#include "array.h"

struct node {
	int data;
	int count;
};

bool compare(node a, node b){
	return (a.count > b.count);
}

void sortFrequency(int *a, int n){
	sort(a, a+n);
	vector<node> V;
	node tmp = {a[0], 1};
	int last = a[0];
	for(int i=1; i<n; i++){
		if(a[i] == tmp.data){
			tmp.count++;
		}
		else {
			V.push_back(tmp);
			tmp.data = a[i];
			tmp.count = 1;
		}
	}
	V.push_back(tmp);
	sort(V.begin(), V.end(), compare);
	int j=0;
	for(int i=0; i<V.size(); i++){
		int data = V[i].data;
		int count = V[i].count;
		while(count){
			a[j] = data;
			count--;
			j++;
		}
	}
}

int main(){
	int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
	int n = sizeof(arr)/sizeof(int);
	sortFrequency(arr, n);
	printArray(arr, n);
	return 0;
}

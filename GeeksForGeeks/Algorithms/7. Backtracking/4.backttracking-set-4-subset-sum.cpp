// http://www.geeksforgeeks.org/backttracking-set-4-subset-sum/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int _count = 0;

bool compare(int a, int b){
	return a < b;
}

void printArray(int *a, int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

void generate(int *w, int n, int target, int *res, int idx){
	_count += 1;
	if(n == 0){
		return;//printArray(res, idx);
	}
	if(w[0] == target){
		res[idx] = w[0];
		idx++;
		printArray(res, idx);
	}
	if(w[0] > target)
		return;
	res[idx] = w[0];
	generate(w+1, n-1, target-w[0], res, idx+1);
	generate(w+1, n-1, target, res, idx);
}

void generateSubsets(int *weight, int n, int target){
	int *res = new int[n];
	sort(weight, weight+n, compare);
	generate(weight, n, target, res, 0);
	delete[] res;
}

int main(){
	int weights[] = {15, 22, 14, 26, 32, 9, 16, 8};
    int target = 53;

    int size = sizeof(weights)/sizeof(int);

    generateSubsets(weights, size, target);
    printf("Nodes generated %d\n", _count);
	return 0;
}


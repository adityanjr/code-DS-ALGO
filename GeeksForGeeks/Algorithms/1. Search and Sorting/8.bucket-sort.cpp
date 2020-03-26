// http://www.geeksforgeeks.org/bucket-sort-2/
#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
//#include <vector>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

void printArray(float a[], int start, int end) {
	for (int i=start; i<=end; i++) {
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}

void bucketSort(float arr[], int start, int end) {
	int n = end-start+1;
	vector<float> v[n];
	for (int i = start; i <= end; ++i) {
		int ind = n*arr[i];		//Since range is from 0-1
		v[ind].push_back(arr[i]);
	}
	for (int i = 0; i < n; ++i)
		sort(v[i].begin(), v[i].end());
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			arr[ind] = v[i][j];
			ind++;
		}
	}
}

int main(){
	float arr[] = {0.99, 0.9, 0.8, 0.7, 0.75, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
	bucketSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	printArray(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	return 0;
}
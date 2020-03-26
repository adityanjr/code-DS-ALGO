// http://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys

#include <bits/stdc++.h>
using namespace std;

struct job {
	int start, finish, profit;
};

bool cmp(job a, job b){
	return a.finish < b.finish;
}

int latestNonConflict(job *arr, int n){
	for(int i=n-1; i>=0; i--){
		if(arr[i].finish <= arr[n].start)
			return i;
	}
	return -1;
}

int findMaxProfit(job *arr, int n){
	sort(arr, arr + n, cmp);
	int cache[n];
	memset(cache, 0, sizeof(cache));
	cache[0] = arr[0].profit;
	for(int i=1; i<n; i++){
		int inc = arr[i].profit;
		int idx = latestNonConflict(arr, i);
		if(idx != -1){
			inc += cache[idx];
		}
		cache[i] = max(cache[i-1], inc);
	}
	int res = cache[n-1];
	delete[] cache;
	return res;
}

int main() {
	job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
}

// http://www.geeksforgeeks.org/tug-of-war

#include <iostream>
#include <cmath>
using namespace std;

int getDiff(int *arr, bool *curr, int n){
	int inc = 0;
	int exc = 0;
	for(int i=0; i<n; i++){
		if(curr[i])
			inc += arr[i];
		else
			exc += arr[i];
	}
	return abs(inc-exc);
}

void solve(int *arr, int n, bool *curr, bool *res, int &min, int inc, int exc){
	if(n == inc+exc){
		int tmp = getDiff(arr, curr, n);
		if(tmp < min){
			min = tmp;
			for(int i=0; i<n; i++)
				res[i] = curr[i];
		}
		return;
	}
	int idx = inc+exc;
	if(inc == (n+1)/2){
		for(; idx<n; idx++){
			curr[idx] = 0;
			exc++;
		}
		solve(arr, n, curr, res, min, inc, exc);
		return;
	}
	else if(exc == (n+1)/2){
		for(; idx<n; idx++){
			curr[idx] = 1;
			inc++;
		}
		solve(arr, n, curr, res, min, inc, exc);
		return;
	}
	curr[idx] = 1;
	solve(arr, n, curr, res, min, inc+1, exc);
	curr[idx] = 0;
	solve(arr, n, curr, res, min, inc, exc+1);
}

void tugOfWar(int *arr, int n){
	bool *curr = new bool[n];
	bool *res = new bool[n];
	int min = INT_MAX;
	solve(arr, n, curr, res, min, 0, 0);
	for(int i=0; i<n; i++){
		if(res[i])
			cout<<arr[i]<<" ";
	}
	cout<<'\n';
	for(int i=0; i<n; i++){
		if(!res[i])
			cout<<arr[i]<<" ";
	}
	cout<<'\n'<<"min->"<<min;
}

int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
	return 0;
}


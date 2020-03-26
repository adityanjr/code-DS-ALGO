// http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k

#include <bits/stdc++.h>
using namespace std;

void printKMax(int *arr, int n, int k){
	list<int> q;
	for(int i=0; i<k; i++){
		while(!q.empty() && arr[i] >= arr[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
	for(int i=k; i<n; i++){
		cout<<arr[q.front()]<<" ";
		while(!q.empty() && i-q.front() >= k)
			q.pop_front();
		while(!q.empty() && arr[i] >= arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout << arr[q.front()];
}

int main(){
	int arr[] = {12, 1, 78, 90, 57, 89, 56};
	int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
}

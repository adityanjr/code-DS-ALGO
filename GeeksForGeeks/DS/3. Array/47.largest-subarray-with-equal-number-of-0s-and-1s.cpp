// http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

#include <bits/stdc++.h>
using namespace std;

void printArray(int *a, int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

void findSubArray(int *a, int n){
	int leftSum[n];
	int sum=0;
	int k=0, l=-1;
	int Max = -1;
	for(int i=0; i<n; i++){
		if(a[i]){
			sum++;
		}
		else{
			sum--;
		}
		leftSum[i] = sum;
	}
	printArray(leftSum, n);
	int i=n-1;
	while(i>=0){
		if(leftSum[i]==0){
			l=i;
			Max = l-k+1;
			break;
		}
		i--;
	}
	map<int, int> M;
	for(int i=0; i<n; i++){
		if(M.count(leftSum[i]) == 0)
			M[leftSum[i]] = i;
		else {
			Max = max(Max, i-M[leftSum[i]]);
		}
	}
	cout<<Max;
	return;
}

int main(){
    int arr[] =  {1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    findSubArray(arr, size);
}

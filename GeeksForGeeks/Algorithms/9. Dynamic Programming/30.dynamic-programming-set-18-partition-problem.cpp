// http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem

#include <bits/stdc++.h>
using namespace std;

int bar(int *a, int n){
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	sum /= 2;
	bool cache[n+1][sum+1];
	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i == 0)
				cache[i][j] = false;
			else if(j == 0)
				cache[i][j] = true;
			else if(j == a[j-1])
				cache[i][j] = true;
			else{
				if(j >= a[i-1])
					cache[i][j] = (cache[i-1][j] || cache[i-1][j-a[i-1]]);
				else
					cache[i][j] = cache[i-1][j];
			}
		}
	}
	return (cache[n][sum] == 1);
}

int main(){
	int arr[] = {3, 1, 1, 2, 2, 1};
  	int n = sizeof(arr)/sizeof(arr[0]);
  	if (bar(arr, n) == true)
     	printf("Can be divided into two subsets of equal sum");
  	else
     	printf("Can not be divided into two subsets of equal sum");

	return 0;
}

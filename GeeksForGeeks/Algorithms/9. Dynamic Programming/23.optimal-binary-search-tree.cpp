// http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

int sum(int *f, int start, int end){
	int sum = 0;
	for(int i=start; i<=end; i++)
		sum += f[i];
	return sum;
}

int optimalSearchTree(int *keys, int *freq, int n){
	int cache[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j)
				cache[i][j] = freq[i];
			else
				cache[i][j] = INT_MAX;
		}
	}
	int cost;
	for(int L=2; L<=n; L++){
		for(int i=0; i<n; i++){
			int j = i+L-1;
			for(int r=i; r<=j; r++){
				cost = ((r>i) ? cache[i][r-1]:0) + ((r<j) ? cache[r+1][j]:0) + sum(freq, i, j);
				if(cost < cache[i][j])
					cache[i][j] = cost;
			}
		}
	}
	return cache[0][n-1];
}

int main(){
	//Sorted
 	int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
	return 0;
}


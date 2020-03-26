// http://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum

#include <bits/stdc++.h>
using namespace std;


int finalCount(int n, int sum){
	int cache[n+1][sum+1];
	for(int i=0; i<=sum; i++){
		cache[0][i] = 0;
		if(i<10)
			cache[1][i] = 1;
		else
			cache[1][i] = 0;
	}
	for(int i=2; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j == 0){
				cache[i][j] = 0;
				continue;
			}
			cache[i][j] = cache[i-1][j];
			for(int s=1; s<=9 && s<j; s++){
				cache[i][j] += cache[i-1][j-s];
			}
		}
	}
	return cache[n][sum];
}

int main(){
	int n = 3, sum = 6;
    cout << finalCount(n, sum);
}

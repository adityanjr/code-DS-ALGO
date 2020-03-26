// http://www.geeksforgeeks.org/shortest-common-supersequence/
/*
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
*/

#include <bits/stdc++.h>
using namespace std;

int superSeq(char *a, char *b, int n, int m){
	int cache[n+1][m+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0)
				cache[i][j] = j;
			else if(j==0)
				cache[i][j] = i;
			else if(a[i] == b[j])
				cache[i][j] = cache[i-1][j-1] + 1;
			else
				cache[i][j] = min(cache[i-1][j], cache[i][j-1]) + 1;
		}
	}
	return cache[n][m];
}

int main(){
	char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout << "Length of the shortest supersequence is "<< superSeq(X, Y, strlen(X), strlen(Y));
	return 0;
}
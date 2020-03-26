// http://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
/*
Given two strings A and B, the task is to convert A to B if possible. The only operation allowed is to put any character from A and insert it at front. Find if it’s possible to convert the string. If yes, then output minimum no. of operations required for transformation.
*/

#include <bits/stdc++.h>
using namespace std;

int minOps(char *a, char *b){
	int n = strlen(b);
	int help[256];
	memset(help, 0, sizeof(help));
	for(int i=0; i<n; i++){
		help[a[i]]++;
		help[b[i]]--;
	}
	for(int i=0; i<n; i++){
		if(help[i]){
			return -1;
		}
	}
	int res = 0;
	int i=n-1, j=n-1;
	while(i>=0){
		while(i>=0 && a[i] != b[j]){
			i--;
			res++;
		}
		//A == B
		i--;
		j--;
	}
	return res;
}

int main(){
	char A[] = "EACBD";
    char B[] = "EABCD";
    cout << "Minimum number of operations required is " << minOps(A, B);
	return 0;
}
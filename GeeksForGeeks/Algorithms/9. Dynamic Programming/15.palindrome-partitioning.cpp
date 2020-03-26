// http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning

#include <iostream>
#include <cstring>
using namespace std;

int minPalPartition(char *str){
	int n = strlen(str);
	int C[n];
	bool P[n][n];
	
	int i, j, k, L;
	for(int i=0; i<n; i++){
		P[i][i] = true;
	}
	
	for(int L=2; L<n; L++){
		for(int i=0; i<n-L+1; i++){
			j = i+L-1;
			if(L==2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
		}
	}
	
	for(int i=0; i<n; i++){
		if(P[0][i] == 1)
			C[i] = 0;
		else {
			C[i] = INT_MAX;
			for(int j=0 ;j<i; j++){
				if(P[j+1][i] && 1+C[j] < C[i])
					C[i] = C[j]+1;
			}
		}
		cout<<C[i]<<" ";
	}
	return C[n-1];
}

int main(){
	char str[] = "ababbbabbababa";
   	printf("Min cuts needed for Palindrome Partitioning is %d", minPalPartition(str));
	return 0;
}


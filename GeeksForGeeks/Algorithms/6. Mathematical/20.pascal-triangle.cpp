// http://www.geeksforgeeks.org/pascal-triangle/

#include <iostream>
#include <cstdio>
using namespace std;

void printPascal(int n){
	int a[n][n];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			if(j==0 || j==i){
				a[i][j] = 1;
				continue;
			}
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++)
			cout<<a[i][j]<<" ";
		cout<<'\n';
	}
}

int main(){
	int n = 7;
 	printPascal(n);
	return 0;
}


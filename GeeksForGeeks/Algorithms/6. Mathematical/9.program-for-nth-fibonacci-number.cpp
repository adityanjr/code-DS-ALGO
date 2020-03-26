// http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include <iostream>
#include <cstdio>
using namespace std;

//O(n)  O(1)
int fib(int n){
	if(n==0)
		return 0;
	int a = 0, b=1, c;
	for(int i=2; i<n; i++){
		c = a+b;
		a = b;
		b = c;
	}
	return b;
}

//O(n)  O(1)
void multiply(int F[2][2], int M[2][2]){
	int a = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int b = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	int c = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	int d = F[1][0]*M[0][0] + F[1][1]*M[1][1];
	
	F[0][0] = a;
	F[0][1] = b;
	F[1][0] = c;
	F[1][1] = d;
}

int power(int F[2][2], int n){
	int M[2][2] = {{1, 1}, {1, 0}};
	for(int i=2; i<n; i++){
		multiply(F, M);
	}
}

int fib1(int n){
	if(n==0)
		return 0;
	int F[2][2]=  {{1, 1}, {1, 0}};
	power(F, n-1);
	return F[0][0];
}

int main(){
	int n = 9;
	printf("%d", fib1(n));
	return 0;
}

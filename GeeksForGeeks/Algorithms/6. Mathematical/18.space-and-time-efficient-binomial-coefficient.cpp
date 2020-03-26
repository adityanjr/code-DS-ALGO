// http://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient

#include <iostream>
#include <cstdio>
using namespace std;

/*
C(n, k) = n! / (n-k)! * k!
        = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) *
                                    ( k * (k-1) * .... * 1 ) ]

After simplifying, we get
C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]
*/

int binomialCoeff(int n, int k){
	if(k > n-k)
		k = n-k;
	int res = 1;
	for(int i=0; i<k; i++){
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

int main(){
	int n = 8, k = 2;
    printf ("Value of C(%d, %d) is %d ", n, k, binomialCoeff(n, k) );
	return 0;
}


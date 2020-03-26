// http://www.geeksforgeeks.org/program-to-efficiently-calculate-ex

#include <iostream>
#include <cstdio>
using namespace std;

float exponential(int n, int x){
	float res = 1.0;
	for(int i=n-1; i>0; i--){
		res = 1 + res*x/i;
	}
	return res;
}

int main(){
	int n = 10;
    float x = 1.0f;
    printf("e^x = %f", exponential(n, x));
	return 0;
}


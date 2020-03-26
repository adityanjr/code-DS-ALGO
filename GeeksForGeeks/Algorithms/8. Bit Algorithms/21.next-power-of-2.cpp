// http://www.geeksforgeeks.org/next-power-of-2

#include <bits/stdc++.h>
using namespace std;

int nextPowerOf2(int n){
	n--;
	n |= (n>>1);
	n |= (n>>2);
	n |= (n>>4);
	n |= (n>>8);
	n |= (n>>16);
	return n+1;
}

int main(){
	unsigned int n = 5;
    printf("%d", nextPowerOf2(n));
	return 0;
}


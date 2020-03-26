// http://www.geeksforgeeks.org/compute-the-integer-absolute-value-abs-without-branching

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

int getAbs(int n){
	return n*(((n>0)<<1)-1);
}

int main(){
	int n = -6;
	printf("Absoute value of %d is %u", n, getAbs(n));
	return 0;
}


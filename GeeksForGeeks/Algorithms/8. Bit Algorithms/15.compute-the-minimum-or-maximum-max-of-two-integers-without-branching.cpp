// http://www.geeksforgeeks.org/compute-the-minimum-or-maximum-max-of-two-integers-without-branching

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

int min(int x, int y){
	return y^((x^y)& -(x<y));
}

int max(int x, int y){
	return y^((x^y) & -(x>y));
}

int main(){
	int x = 15;
  	int y = 6;
  	printf("Minimum of %d and %d is ", x, y);
  	printf("%d", min(x, y));
  	printf("\nMaximum of %d and %d is ", x, y);
  	printf("%d", max(x, y));
	return 0;
}


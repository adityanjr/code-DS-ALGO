// http://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int x){
	if(x == 0)
		return 0;
	while((x&1)==0 && ((x>>1)&1)==0){
		x >>= 2;
	}
	if(x == 1)
		return 1;
	return 0;
}

int main(){
	int test_no = 64;
   if(isPowerOfFour(test_no))
     printf("%d is a power of 4", test_no);
   else
     printf("%d is not a power of 4", test_no);
	return 0;
}


// http://www.geeksforgeeks.org/count-set-bits-in-an-integer

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n){
	int count = 0;
	while(n){
		n &= (n-1);
		count++;
	}
	return count;
}

int main(){
	int i = 15;
    printf("%d", countSetBits(i));
	return 0;
}


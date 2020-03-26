// http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

typedef unsigned int ui;

ui reverseBits(ui x){
	ui tmp = x;
	int Bits = 32;
	int count = 1;
	while(tmp&1){
		x |= (1<<(Bits-count));
		x ^= (1<<(count-1));
		tmp >>= 1;
		count++;
	}
	return x;
}

int main(){
	unsigned int x = 7;
	printBinary(x);
	ui y =reverseBits(x);
	printBinary(y);
    printf("%u", y);
	return 0;
}


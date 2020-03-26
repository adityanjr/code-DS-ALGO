// http://www.geeksforgeeks.org/swap-all-odd-and-even-bits

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

typedef unsigned int ui;

ui swapBits(ui x){
	int b = x&1;
	ui even_bits = x & 0xAAAAAAAA;
	ui odd_bits  = x & 0x55555555;
	return (even_bits>>1)|(odd_bits<<1);
}

int main(){
	 unsigned int x = 23; // 00010111
    // Output is 43 (00101011)
    printf("%u ", swapBits(x));
	return 0;
}


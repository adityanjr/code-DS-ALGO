// http://www.geeksforgeeks.org/swap-bits-in-a-given-number

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

int swapBits(int n, int pos1, int pos2, int k){
	// 00101111
    int set1 = (n>>pos1) & ((1U << k)-1);   // (00010111)&(00000111)
	int set2 = (n>>pos2) & ((1U << k)-1);   // 001&111
	int Xor = set1^set2;
	Xor = (Xor<<pos1) | (Xor<<pos2);
    return n^Xor;
}

int main() {
    int res =  swapBits(47, 1, 5, 3);
    printf("\nResult = %d \n", res);
    printBinary(47);
    printBinary(res);
	return 0;
}

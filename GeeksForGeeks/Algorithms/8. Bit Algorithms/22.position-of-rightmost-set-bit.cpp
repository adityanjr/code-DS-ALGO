// http://www.geeksforgeeks.org/position-of-rightmost-set-bit

#include <bits/stdc++.h>
using namespace std;

unsigned int getFirstSetBitPos(int n) {
   return log2(n&-n)+1;
}

int main() {
    int n = 12;
    printf("%u", getFirstSetBitPos(n));
}

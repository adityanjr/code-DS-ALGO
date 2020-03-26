// http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits

#include <bits/stdc++.h>
#include "bit.h"
using namespace std;

int snoob(int x){
    if(x == 0)
        return -1;
    int pos = 0;
    int count0 = 0;
    int count1 = 0;
    int tmp = x;
    while(tmp && !(tmp&1 && ((tmp>>1)&1) == 0)){
        if(tmp&1){
            count1++;
        }
        else {
            count0++;
        }
        tmp >>= 1;
    }
    int res = (((tmp>>1)|1)<<1);
    res <<= count0;
    while(count1){
        res <<= 1;
        res |= 1;
        count1--;
    }
    return res;
}

int main(){
    int x = 156;
    printBinary(x);
    int y = snoob(x);
    printBinary(y);
    cout<<"Next higher number with same number of set bits is "<<y<<'\n';
    return 0;
}

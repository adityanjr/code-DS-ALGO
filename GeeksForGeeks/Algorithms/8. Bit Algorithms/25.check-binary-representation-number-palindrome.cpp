// http://www.geeksforgeeks.org/check-binary-representation-number-palindrome

#include <iostream>
#include "bit.h"
using namespace std;

typedef unsigned int ui;

bool isPalindrome(ui x){
    int l = 1;
    int r = sizeof(ui)*8;
    r = 1<<(r-1);
    int k = 16;
    while(k--){
//        cout<<"#"<<(x&l)<<" "<<(x&r)<<'\n';
        if((x&l) >0 && (x&r) == 0)
            return false;
        if((x&l) == 0 && (x&r) > 0)
            return false;
        l <<= 1;
        r >>= 1;
    }
    return true;
}

int main(){
    unsigned int x = 1<<15 + 1<<16;
    cout << isPalindrome(x) << endl;
    x = 1<<31 + 1;
    cout << isPalindrome(x) << endl;
    return 0;
}

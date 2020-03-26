// http://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/

#include <iostream>
using namespace std;

bool isMultipleOf3(int n){
    int odd = 0, even = 0;
    if(n<0)
        n = -n;
    if(n==0)
        return 1;
    if(n==1 || n==2)
        return 0;
    while(n){
        if(n&1)
            odd++;
        n = n>>1;
        if(n&1)
            even++;
        n = n>>1;
    }
    return isMultipleOf3(odd-even);
}

int main() {
    int num = 23;
    if (isMultipleOf3(num))
        printf("num is multiple of 3");
    else
        printf("num is not a multiple of 3");
	return 0;
}



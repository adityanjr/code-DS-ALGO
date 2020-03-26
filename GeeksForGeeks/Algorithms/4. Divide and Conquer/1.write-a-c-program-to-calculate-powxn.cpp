// http://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn

#include <iostream>
#include <cstdio>
using namespace std;

int power(int x, unsigned int y){
    if(y == 1)
        return x;
    int a = power(x, y/2);
    if(y%2){
       return a*a*x;
    }
    else
        return a*a;
}

int main(){
    int x = 2;
    unsigned int y = 20;

    printf("%d", power(x, y));
    return 0;
}

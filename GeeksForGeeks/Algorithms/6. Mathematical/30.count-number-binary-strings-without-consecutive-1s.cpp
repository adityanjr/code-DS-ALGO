//http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s

#include <iostream>
#include <cstdio>
using namespace std;

int countString(int n, string str){
    if(n == 1){
        if(str[0] == '1')
            return 1;
        else
            return 2;
    }
    if(str != "" && str[0] == '1')
        return countString(n-1, '0' + str);
    return countString(n-1, '1' + str) + countString(n-1, '0' + str);
}

int main(){
    cout << countString(3, "") << endl;
    return 0;
}

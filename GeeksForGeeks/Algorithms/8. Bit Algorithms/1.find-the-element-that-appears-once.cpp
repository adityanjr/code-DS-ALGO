// http://www.geeksforgeeks.org/find-the-element-that-appears-once

#include <iostream>
using namespace std;

int getSingle(int *arr, int n){
    int ones = 0, twos = 0;
    int common_bit = 0;
    for(int i=0; i<n; i++){
        twos = twos | (ones & arr[i]);
        //cout<<twos<<" ";
        ones = ones^arr[i];
        //cout<<ones<<" ";
        common_bit = ~(ones&twos);
        //cout<<common_bit<<" ";
        ones &= common_bit;
        //cout<<ones<<" ";
        twos &= common_bit;
        //cout<<twos<<"\n";
    }
    return ones;
}

int main() {
    int arr[] = {3, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The element with single occurrence is %d ", getSingle(arr, n));
	return 0;
}



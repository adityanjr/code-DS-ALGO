// http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod

#include <iostream>
using namespace std;

int cutRod(int *arr, int n) {
    int cache[n+1];
    cache[0] = 0;
    int i, j;

    for(int i=1; i<=n; i++){
        int max_ = INT_MIN;
        for(int j=0; j<i; j++){
            max_ = max(max_, price[j] + cache[i-j-1]);
        }
        cache[i] = max_;
    }
    return cache[n];
}

int main() {
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
	return 0;
}



// http://geeksquiz.com/construct-array-pair-sum-array/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void constructArr(int *a, int *pair, int n){
	int m = (n*(n-1))/2;
	a[0] = (pair[0]+pair[1]-pair[n-1])/2;
	for(int i=1; i<n; i++){
		a[i] = pair[i-1]-a[0];
	}
}

int main(){
	int pair[] = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5};
    int n = 5;
    int arr[n];
    constructArr(arr, pair, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
	return 0;
}
// http://www.geeksforgeeks.org/dynamic-programming-set-20-maximum-length-chain-of-pairs

#include <iostream>
#include <algorithm>
using namespace std;

struct _pair{
	int a, b;
};

bool compare(_pair a, _pair b){
	return a.a < b.a;
}

int maxChainLength(_pair *arr, int n){
	sort(arr, arr+n, compare);
	int cache[n];
	for(int i=0; i<n; i++)
		cache[i] = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i].a > arr[j].b && cache[i] < cache[j] + 1)
				cache[i] = cache[j] + 1;
		}
	}
	int m = 0;
	for(int i=0; i<n; i++)
		m = max(m, cache[i]);
	return m;
}

int main(){
	struct _pair arr[] = {{15, 25}, {5, 24}, {27, 40}, {50, 60}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n", maxChainLength( arr, n ));
	return 0;
}


// http://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion

#include <iostream>
#include <ctime>
using namespace std;

int findRandIdx(int *f, int n, int Max){
	int i = rand()%Max + 1;
	int start = 0, end = n-1;
	while(start<end){
		int mid = (start+end+1)/2;
		if(f[mid] >= i && f[mid-1] < i)
			return mid;
		else if(f[mid] > i){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return start;
}

int myRand(int *arr, int *freq, int n){
	int pre[n];
	pre[0] = freq[0];
	for(int i=1; i<n; i++)
		pre[i] = pre[i-1] + freq[i];
	return arr[findRandIdx(freq, n, pre[n-1])];
}

int main(){
	int arr[]  = {1, 2, 3, 4};
    int freq[] = {10, 5, 20, 100};
    int i, n = sizeof(arr) / sizeof(arr[0]);

    // Use a different seed value for every run.
    srand(time(NULL));

    // Let us generate 10 random numbers accroding to
    // given distribution
    for (i = 0; i < 5; i++)
      printf("%d\n", myRand(arr, freq, n));
	return 0;
}


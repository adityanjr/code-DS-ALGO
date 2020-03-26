// http://www.geeksforgeeks.org/average-of-a-stream-of-numbers/

#include <iostream>
#include <cstdio>
using namespace std;

void streamAvg(float *arr, int n){
	int i=0;
	float avg = arr[0];
	cout<<avg<<" ";
	for(i=1; i<n; i++){
		int num = avg*(i) + arr[i];
		avg = num/(i+1);
		cout<<avg<<" ";
	}
}

int main(){
	float arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    streamAvg(arr, n);
	return 0;
}


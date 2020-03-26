// http://www.geeksforgeeks.org/find-subarray-with-given-sum/

#include <iostream>
#include "array.h"

void subArraySum(int *a, int n, int sum){
	int curSum = a[0];
	int i=0, j=0;
	while(i<n && i<=j){
		if(curSum == sum){
			cout<<i<<" "<<j;
			return;
		}
		else if(curSum < sum){
			j++;
			curSum += a[j];
		}
		else {
			if(i<j){
				curSum -=a[i];
				i++;
			}
			else {
				j++;
				curSum +=a[j];
			}
		}
	}
}

int main(){
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    subArraySum(arr, n, sum);
    return 0;
}

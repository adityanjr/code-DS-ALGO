// http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

#include <iostream>
#include <map>
#include "array.h"

bool printZeroSumSubarray(int *a, int n){
	map<int, int> M;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum += a[i];
		if(M.count(sum) != 0){
			cout<<M[sum]+1<<" "<<i<<'\n';
			return true;
		}
		else
			M[sum] = i;
	}
	return false;
}

int main(){
	int arr[] = {4, 2, -3, 0, 6};
    if (printZeroSumSubarray(arr, sizeof(arr)/sizeof(int)))
        cout<<"Found a subarray with 0 sum";
        else
            cout<<"No Subarray with 0 sum";
	return 0;
}


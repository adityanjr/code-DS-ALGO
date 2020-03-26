// http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

#include <iostream>
#include "array.h"

struct pump{
	int p, d;
};

int printTour(pump *a, int n){
	int start = 0;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum = a[i].p-a[i].d;
		int j=i+1;
		while(j != i && sum>0){
			if(j>=n)
				j=0;
			sum += (a[j].p-a[j].d);
			j++;
		}
		if(j==i){
			return i;
		}
	}
}

int main(){
	pump arr[] = {{6, 4}, {3, 6}, {7, 3}};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
	return 0;
}


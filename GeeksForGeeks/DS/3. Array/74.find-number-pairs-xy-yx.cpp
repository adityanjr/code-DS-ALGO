// http://www.geeksforgeeks.org/find-number-pairs-xy-yx/
/**Incomplete**/
 
#include <iostream>
#include <algorithm>
#include <cmath>
#include "array.h"

bool comp(int x, int y){
	return (pow(x, y) > pow(y, x));
}

// If y > x then x^y > y^x
int countPairs(int *a, int *b, int n, int m){
	sort(b, b+m);
	int count = 0;
	int *idx;
	int noOfY[5] = {0};
	for(int i=0; i<m; i++){
		if(b[i] < 5)
			noOfY[b[i]]++;
		else
		break;
	}
	for(int i=0; i<n; i++){
		idx = upper_bound(b, b+m, a[i]);
		if(a[i] < 4){
			for(int j=0; j<m; j++){
				cout<<a[i]<<" "<<b[j]<<" "<<comp(a[i], b[j])<<'\n';
				if(comp(a[i], b[j]))
					count++;
			}
		}
		else {
			cout<<(m-(idx-b))<<'\n';
			count += (m-(idx-b));
		}
	}
	return count;
}

int main(){
	int X[] = {2, 1, 6};
    int Y[] = {1, 5};
 
    int m = sizeof(X)/sizeof(X[0]);
    int n = sizeof(Y)/sizeof(Y[0]);
    cout << "Total pairs = " << countPairs(X, Y, m, n);
	return 0;
}


// http://www.geeksforgeeks.org/check-given-array-contains-duplicate-elements-within-k-distance/

#include <iostream>
#include <map>
#include "array.h"

bool checkDuplicatesWithinK(int *a, int n, int k){
	map<int, bool> M;
	map<int, bool>::iterator it;
	for(int i=0; i<n; i++){
		it = M.find(a[i]);
		if(it != M.end()){
			cout<<it->first<<'\n';
			return true;
		}
		else {
			it = M.find(a[i-k]);
			if(it != M.end())
				M.erase(it);
			M[a[i]] = true;
		}
	}
	return false;
}

int main(){
	 int arr[] = {10, 5, 3, 4, 6, 5, 3};
     if (checkDuplicatesWithinK(arr, sizeof(arr)/sizeof(int), 3))
           cout<<"Yes";
        else
           cout<<"No";
	return 0;
}


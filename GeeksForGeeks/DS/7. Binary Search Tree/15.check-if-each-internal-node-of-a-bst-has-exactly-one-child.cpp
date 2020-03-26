// http://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child

#include <iostream>
#include "bst.h"

bool hasOnlyOneChild(int *pre, int size){
	if(size <= 0)
		return true;
	int min = INT_MIN;
	int max = INT_MAX;
	int i=0;
	for(; i<size-1; i++){
		if(pre[i] < min || pre[i] > max)
			return false;
		if(pre[i] > pre[i+1]){
			max = pre[i];
		}
		else {
			min = pre[i];
		}
	}
	if(pre[i] < min || pre[i] > max)
		return false;
	return true;
}

int main(){
	int pre[] = {8, 3, 5, 7, 6};
    int size = sizeof(pre)/sizeof(pre[0]);
    if (hasOnlyOneChild(pre,size))
        printf("Yes");
    else
        printf("No");
	return 0;
}


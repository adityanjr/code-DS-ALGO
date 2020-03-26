// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x

#include <iostream>
#include <algorithm>
using namespace std;

bool hasArrayTwoCandidates(int *A, int n, int x){
	sort(A, A+n);
	int start=0, end=n-1;
	while(start < end){
		int val = A[start] + A[end];
		if(val == x)
  		    return true;
		else if(val > x)
		    end--;
  		else
		    start++;	
	}
	return false;
}

int main(){
    int A[] = {1, 4, 45, 6, 10, -8};
    int n = 16;
    int arr_size = 6;
    
    if( hasArrayTwoCandidates(A, arr_size, n))
        printf("Array has two elements with sum 16");
    else
        printf("Array doesn't have two elements with sum 16 ");
 
    getchar();
    return 0;
}

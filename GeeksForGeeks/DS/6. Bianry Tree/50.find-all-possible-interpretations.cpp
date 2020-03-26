// http://www.geeksforgeeks.org/find-all-possible-interpretations/

#include <iostream>
#include "bt.h"

#define A int('a')

struct Node{
	string data;
	node *left, *right;
};

void printAllInterpretations(int *arr, int n, string res){
	if(n <= 0){
		cout<<res<<'\n';
		return;
	}
	printAllInterpretations(arr+1, n-1, res+char(A + arr[0]-1));
	if(n>1){
		int tmp = arr[0]*10 + arr[1];
		if(tmp <= 26){
			printAllInterpretations(arr+2, n-2, res+char(A + tmp -1));
		}
	}
}

int main(){
	// aacd(1,1,3,4) amd(1,13,4) kcd(11,3,4)
    // Note : 1,1,34 is not valid as we don't have values corresponding
    // to 34 in alphabet
    int arr[] = {1, 1, 3, 4};
    printAllInterpretations(arr, 4, "");

        // aaa(1,1,1) ak(1,11) ka(11,1)
        int arr2[] = {1, 1, 1};
        printAllInterpretations(arr2, 3, "");

        // bf(2,6) z(26)
        int arr3[] = {2, 6};
        printAllInterpretations(arr3, 2, "");

        // ab(1,2), l(12)
        int arr4[] = {1, 2};
        printAllInterpretations(arr4, 2, "");

        // a(1,0} j(10)
        int arr5[] = {1, 0};
        printAllInterpretations(arr5, 2, "");

        // "" empty string output as array is empty
        int arr6[] = {};
        printAllInterpretations(arr6, 0, "");

        // abba abu ava lba lu
        int arr7[] = {1, 2, 2, 1};
        printAllInterpretations(arr7, 4, "");
	return 0;
}


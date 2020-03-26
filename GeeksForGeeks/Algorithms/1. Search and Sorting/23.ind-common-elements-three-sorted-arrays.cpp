// http://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

#include <iostream>
#include <climits>
#include <cstdio>
//#include <cmath>
//#include <vector>
//#include <string>
using namespace std;

void func(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3){
	int i=0, j=0, k=0;
	while (i < n1 && j < n2 && k < n3) {
		if(arr1[i] == arr2[j] && arr1[i] == arr3[k]) {
			cout<<arr1[i]<<" ";
			i++; j++; k++;
		}
		else if(arr1[i] < arr2[j] && arr1[i] < arr3[k])
			i++;
		else if(arr2[j] < arr3[k])
			j++;
		else
			k++;
	}
}

int main(){
	/*
	int arr1[] = {1, 5, 10, 20, 40, 80};
	int arr2[] = {6, 7, 20, 80, 100};
	int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
	*/
	int arr1[] = {1, 5, 5};
	int arr2[] = {3, 4, 5, 5, 10};
	int arr3[] = {5, 5, 10, 20};
	func(arr1, arr2, arr3, sizeof(arr1)/sizeof(*arr1), sizeof(arr2)/sizeof(*arr2), sizeof(arr3)/sizeof(*arr3));
	return 0;
}
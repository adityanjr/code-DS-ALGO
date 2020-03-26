// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>
using namespace std;

int binarySearch(int *a, int start, int end, int x){
	if(start>end)
 	    return -1;
	int mid = (end+start)/2;
	if(a[mid] == x)
 	    return mid;
	else if(a[mid] > x)
		 return binarySearch(a, start, mid-1, x);
    return binarySearch(a, mid+1, end, x);
}

int getPivot(int *a, int start, int end){
	if(start>end)
 	    return -1;
	if(start == end)
 	    return start;
	int mid = (end+start)/2;
	if(mid < end && a[mid] > a[mid+1]){
		return mid;
	}
	else if(start < mid && a[mid] < a[mid-1])
		 return (mid-1);
	else {
		if (a[start] < a[mid])
		   return getPivot(a, mid+1, end);
        return getPivot(a, start, mid-1);
	}
}

int getPivotIter(int *a, int start, int end){
	while(start <= end){
		if(start == end){
			return start;
		}
		if(end-start == 1){
			if(a[start] < a[end])
				return start;
			return end;
		}
		int mid = start + (end-start)/2;
		if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
			return mid;
		if(a[start] < a[mid] && a[start] < a[end])
			return -1;
		if(a[start] < a[mid]){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return -1;
}

int pivotedBinarySearch(int *a, int n, int x){
	int piv = getPivot(a, 0, n-1);
	cout<<piv<<'\n';
	int ind = binarySearch(a, 0, piv, x);
	if(ind == -1)
 	    return binarySearch(a, piv+1, n-1, x);
	else
		return ind;
}

int main(){
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int arr_size = sizeof(arr1)/sizeof(arr1[0]);
   int no = 3;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr1, arr_size, no));
 
    // Let us search 3 in below array
   int arr2[] = {3, 4, 5, 1, 2};
   arr_size = sizeof(arr2)/sizeof(arr2[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));
 
   // Let us search for 4 in above array
   no = 4;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr2, arr_size, no));
 
   // Let us search 0 in below array
   int arr3[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
   no = 0;
   arr_size = sizeof(arr3)/sizeof(arr3[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr3, arr_size, no));
 
   // Let us search 3 in below array
   int arr4[] = {2, 3, 0, 2, 2, 2, 2, 2, 2, 2};
   no = 3;
   arr_size = sizeof(arr4)/sizeof(arr4[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));
 
   // Let us search 2 in above array
   no = 2;
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr4, arr_size, no));
 
   // Let us search 3 in below array
   int arr5[] = {1, 2, 3, 4};
   no = 3;
   arr_size = sizeof(arr5)/sizeof(arr5[0]);
   printf("Index of the element is %d\n",  pivotedBinarySearch(arr5, arr_size, no));
 
   return 0;
}

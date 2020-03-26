//http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int *arr, int start, int end, int x) {
	
	int j = start;
	int ind = -1;
	for (int i = start; i <= end; ++i) {
		if(arr[i] < x) {
			swap(arr[j], arr[i]);
			j++;
		}
		else if(arr[i] == x) {
			ind = i;
		}
	}
	swap(arr[j], arr[ind]);
	return j;
}

int quickSelection(int *arr, int start, int end, int k){
	int n = end-start+1;
	if (k>0 && n >= k){
		if(n==1)
			return arr[start];
		int i=start;
		int len = ceil(float(end-start)/5);
		int median[len];
		int j=0;
		while(end - i > 4) {
			sort(arr+i, arr+i+5);
			median[j] = arr[i+2];
			j++;
			i += 5;
		}
		if(i<end) {
			sort(arr+i, arr+end+1);
			median[j] = arr[i+int((end-i)/2)];
		}
		int midOfmid;
		if(len==1)
			midOfmid = median[0];
		else
			midOfmid = quickSelection(median, 0, len-1, len/2);
		//cout<<"#"<<midOfmid;
		int ind = partition(arr, start, end, midOfmid);
		//cout<<"@"<<ind;
		if(ind-start+1 == k)
			return midOfmid;
		else if(ind-start+1 > k)
			return quickSelection(arr, start, ind-1, k);
		else
			return quickSelection(arr, ind+1, end, k-ind+start-1);
	}
	return -1;
}

int main(){
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	//int arr[] = {4, 3};
    int n = sizeof(arr)/sizeof(arr[0]), k = 5;
	cout << "K'th smallest element is " << quickSelection(arr, 0, n-1, k);
	return 0;
}
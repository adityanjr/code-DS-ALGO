// http://www.geeksforgeeks.org/maximum-sum-path-across-two-arrays
/****/

#include <iostream>
using namespace std;

void printArray(int *a, int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<'\n';
}

//Space O(n)
void rearrangeNaive(int *a, int n){
	int help[n];
	for(int i=0; i<n; i++){
		int idx = a[i];
		help[idx] = i;
	}
	printArray(help, n);
}

//Sapce O(1)
int rearrangeUtil(int *a, int i){
	int idx = a[i]-1;
	while(a[idx] > 0){
		int tmp = a[idx];
		a[idx] = -(i+1);
		idx = tmp-1;
		i++;
	}
}

int rearrange(int *a, int n){
	int i;
    for (i=0; i<n; i++)
        a[i]++;
 
	for(int i=0; i<n; i++){
		if(a[i] > 0)
			rearrangeUtil(a, i);
	}
	for(int i=0; i<n; i++){
		a[i] = -(a[i]+1);
	}
}

int main(){
	int arr[] =  {2, 0, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, n);
 
 
    printf("Modified array is \n");
    //rearrangeNaive(arr,  n);
    rearrange(arr, n);
    printArray(arr, n);

	return 0;
}

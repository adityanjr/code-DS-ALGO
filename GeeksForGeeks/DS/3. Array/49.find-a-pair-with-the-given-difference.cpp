// http://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/

#include <iostream>
#include <algorithm>
using namespace std;

void findPair(int *a, int n, int x){
	sort(a, a+n);
	for(int i=0; i<n; i++){
//		cout<<abs(a[i]+x)<<'\n';
		if(binary_search(a+i+1, a+n, abs(a[i]+x))){
			cout<<"yes"<<"-->"<<a[i]<<" "<<abs(a[i]+x)<<'\n';
		}
	}
}

int main(){
    int arr[] = {1, 8, 30, 40, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 7;
    findPair(arr, size, n);
    return 0;
}

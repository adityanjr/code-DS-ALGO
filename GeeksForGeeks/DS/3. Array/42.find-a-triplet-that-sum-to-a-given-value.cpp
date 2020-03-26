// http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

#include <iostream>
#include <algorithm>
using namespace std;

struct _pair{
	int a, b;
};

_pair find2Numbers(int *a, int n, int sum, int idx){
	int i=idx+1, j=n-1;
	while(i<j){
		if(i == idx)
			i++;
		if(j == idx)
			j--;
		if(a[i]+a[j] == sum)
			return {a[i], a[j]};
		else if(a[i] + a[j] > sum)
			j--;
		else
			i++;
	}
	return {-1, -1};
}

void find3Numbers(int *a, int n, int sum){
	sort(a, a+n);
	for(int i=0; i<n; i++){
		_pair tmp = find2Numbers(a, n, sum-a[i], i);
		if(tmp.a != -1){
			cout<<a[i]<<" "<<tmp.a<<" "<<tmp.b<<'\n';
			return;
		}
	}
}

int main(){
    int A[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int arr_size = sizeof(A)/sizeof(A[0]);
 
    find3Numbers(A, arr_size, sum);
 
    getchar();
    return 0;
}

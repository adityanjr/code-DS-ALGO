#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int arr[n+1];

		for(int i = 0; i < n; i ++) {
			scanf("%d",&arr[i]);
		}

		sort(arr, arr+n);
		arr[n]=-1;
	
		int i = 0;
		while(i < n){
			if(arr[i+1] != arr[i]) {
				printf("%d\n",arr[i]);
				i+=1;
			}
			else if(arr[i+1] == arr[i])
				i+=2;
		}
	
		// for(int i = 0; i <= n; i ++)
		// 	printf("%d\t", arr[i]);
		// printf("\n");
	}
	return 0;
}
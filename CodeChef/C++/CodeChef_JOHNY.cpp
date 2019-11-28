#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		
		int n;
		scanf("%d",&n);
		
		int arr[n];
		for(int i = 0; i < n; i ++) 
			scanf("%d",&arr[i]);
		

		int k, temp, count = 1;
		scanf("%d",&k);
		temp = arr[k-1];

		for(int i = 0; i < n; i ++) {
			if(arr[i] < temp)
				count ++;
		} 

		printf("%d\n",count);

	}


	return 0;
}
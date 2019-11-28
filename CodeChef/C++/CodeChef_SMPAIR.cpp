#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		long long int arr[n];

		for(int i = 0; i < n; i ++) 
			scanf("%lld",&arr[i]);

		sort(arr, arr+n);
		printf("%lld\n",arr[0]+arr[1]);
	}

	return 0;
}
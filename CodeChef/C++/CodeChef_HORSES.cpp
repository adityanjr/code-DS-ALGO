#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		long long int arr[n];
		for(int i = 0; i < n; i ++) {
			scanf("%lld",&arr[i]);
		}

		sort(arr, arr+n);

		long long int min = LLONG_MAX;
		for(int i = 1; i < n; i ++) {
			if(arr[i] - arr[i-1] < min)
				min = arr[i] - arr[i-1];
		}

		printf("%lld\n",min);
	}

	return 0;
}
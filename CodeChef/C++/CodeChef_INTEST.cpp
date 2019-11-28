#include <bits/stdc++.h>

int main() {
	long long int n, k;
	scanf("%lld %lld",&n,&k);
	long long int arr[n];
	long long int count = 0;

	for(long long int i = 0; i < n; i ++) {
		scanf("%lld",&arr[i]);
		if(arr[i] % k == 0)
			count += 1;
	}

	printf("%lld",count);

	return 0;
}
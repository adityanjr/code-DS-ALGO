#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, k;
		scanf("%d %d",&n, &k);

		long long int arr[n+k];
		long long int sum = 0;
		for(int i = 0; i < n; i ++) {
			scanf("%lld",&arr[i]);
			sum += arr[i];
		}

		if(sum % 2 == 0) {
			if(k == 1)
				printf("odd\n");
			else
				printf("even\n");
		} 
		else 
			printf("even\n");
	}

	return 0;
}
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

		for(int i = 0; i < n-1; i ++) {
			if(arr[i+1] != arr[i] + 1) {
				if(i == 0) {
					printf("%lld\n",arr[i]);
					break;
				}
				else
					printf("%lld\n",arr[i+1]);
			}

		}

	}
}
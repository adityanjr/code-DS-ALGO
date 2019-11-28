#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		
		int n, k;
		scanf("%d %d",&n,&k);
		float arr[n];
		
		for(int i = 0; i < n; i ++)
			scanf("%f",&arr[i]);

		sort(arr, arr+n);

		float sum = 0;
		for(int i = 0 + k; i < n - k; i ++) {
			sum += arr[i];
		}
		sum /= (n-2*k);

		printf("%f\n",sum );
	}

	return 0;
}
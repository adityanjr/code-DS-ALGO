#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n;
		scanf("%lld",&n);
		
		double x = n / 5;
		int sum = 0;

		while(x >= 1) {
			sum += (int)x;
			x = x / 5;
		}

		printf("%d\n", sum);
	}
}
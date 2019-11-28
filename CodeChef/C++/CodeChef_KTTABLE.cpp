#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n;
		scanf("%d",&n);

		long long int a[n], b[n];
		for(int i = 0; i < n; i ++)
			scanf("%lld",&a[i]);

		for(int i = 0; i < n; i ++) {
			scanf("%lld",&b[i]);
		}

		for(int i = n -1; i > 0; i --)
			a[i] = a[i] - a[i-1];

		int count = 0;
		for(int i = 0; i < n; i ++)
			if(a[i] >= b[i])
				count++;

		printf("%d\n",count);
	}

	return 0;
}
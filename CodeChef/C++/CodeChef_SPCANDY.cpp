#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t --) {
		long long int n, k;
		cin >> n >> k;
		if(k == 0)
			printf("%lld %lld\n",k,n);
		else
			printf("%lld %lld\n",(long long int)n/k, (long long int)n%k);
	}

	return 0;
}
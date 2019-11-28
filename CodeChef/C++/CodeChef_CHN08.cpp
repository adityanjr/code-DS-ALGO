#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int a, b, n;
		scanf("%lld %lld %lld",&a,&b,&n);
		long long int v[n+2];
		v[0] = a;
		v[1] = b;

		for(int i = 1; i < n; i ++) {
			v[i+1] = ((v[i]) - (v[i-1]));
			// v[i+1] = (v[i+1]%MOD);
			v[i+1] = ((v[i+1]%MOD)+MOD)%MOD;
		}

		printf("%lld\n",v[n-1]);
	}

	return 0;
}
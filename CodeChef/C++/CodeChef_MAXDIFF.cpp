#include <bits/stdc++.h>
using namespace std;

long long int maximum(long long int x, long  long int y) {
	return (x > y) ? x : y;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n, k, temp;
		scanf("%lld %lld",&n,&k);
		vector<int> v;
		for(int i = 0; i < n; i ++) {
			scanf("%lld",&temp);
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		long long int chef1 = 0, kid1 = 0;

		for(int i = 0; i < k; i ++) {
			kid1 += v[i];
		}

		for(int i = k; i < n; i ++) {
			chef1 += v[i];
		}

		int chef2 = 0, kid2 = 0;

		for(int i = n-1; i >= k; i --) {
			kid2 += v[i];
		}

		for(int i = k-1; i >= 0; i --) {
			chef2 += v[i];
		}

		long long int val = maximum(abs(chef2 - kid2), abs(chef1 - kid1));
		
		printf("%lld\n",val);
	}

	return 0;
}
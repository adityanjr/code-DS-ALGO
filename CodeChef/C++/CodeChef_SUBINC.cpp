#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n, temp, count = 0;
		scanf("%d",&n);

		vector<long long int> v;

		int dp[n] = {0};
		dp[0] = 1;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}	

		for(int i = 1; i < n; i ++) {
			if(v[i-1] <= v[i])
				dp[i] = dp[i-1] + 1;
			else
				dp[i] = 1;
		}

		for(int i = 0; i < n; i ++) {
			count += dp[i];
		}

		printf("%d\n",count );

	}

	return 0;
}
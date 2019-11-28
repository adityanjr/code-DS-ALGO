#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		scanf("%d",&n);
		vector<int> v;
		int dp[n];
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		int flag = 0;
		if(v[n-1] >= 0)
			flag = 1;
		int count = 1;
		dp[n-1] = 1;

		for(int i = n - 2; i >= 0; i --) {
			if(flag && v[i] < 0) {
				dp[i] = dp[i+1] + 1;
				flag = 0;
			}
			else if(!flag && v[i] >= 0) {
				dp[i] = dp[i+1] + 1;
				flag = 1;
			}
			else if(flag && v[i] >= 0) {
				dp[i] = 1;
				flag = 1;
			}
			else if(!flag && v[i] < 0) {
				dp[i] = 1;
				flag = 0;
			}
		}

		for(int i = 0; i < n; i ++) {
			printf("%d ",dp[i]);
		}
		printf("\n");
	}
	return 0;
}
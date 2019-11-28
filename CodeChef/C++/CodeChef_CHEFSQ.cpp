#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		
		int n, m, temp, flag = 0;
		vector<int> vn, vm;

		scanf("%d",&n);
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			vn.push_back(temp);
		}

		scanf("%d",&m);
		for(int i = 0; i < m; i ++) {
			scanf("%d",&temp);
			vm.push_back(temp);
		}

		int dp[n]={0};
		if(vn[0] == vm[0]) {
			dp[0] = 1;
		}
		else 
			dp[0] = 0;

		for(int i = 1; i < n; i ++) {
			if(vn[i] == vm[dp[i-1]])
				dp[i] = dp[i-1] + 1;
			else
				dp[i] = 0;
		}

		for(int i = 0; i < n; i ++) {
			if(dp[i] == (vm.size()))
				flag = 1;
		}

		if(flag) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}

	}

}
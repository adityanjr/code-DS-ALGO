#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;
		set<int> set;

		int dp[s.size()] = {0};
		int max = INT_MIN;
		dp[0] = 0;	

		for(int i = 1; i < s.size(); i ++) {
			if(s[i] == '.')
				dp[i] = dp[i-1] + 1;
			else
				dp[i] = 0;

			if((s[i] == '#') && (s[i-1] == '.') && dp[i-1] > max) {
				set.insert(dp[i-1]);
				max = dp[i-1];
			} 

		}

		cout << set.size() << "\n";
	}

	return 0;
}
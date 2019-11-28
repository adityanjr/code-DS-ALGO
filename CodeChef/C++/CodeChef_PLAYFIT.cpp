#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n, temp;
		scanf("%d",&n);
		vector<int> v;
		
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		int ans = v[1]-v[0];
		int mini = v[0];

		for(int i = 1; i < n; i ++) {
			ans = max(ans, v[i]-mini);
			mini = min(mini, v[i]);
		}
		
		if(ans > 0)
			printf("%d\n",ans);
		else
			printf("UNFIT\n");
	}

	return 0;
}

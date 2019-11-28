#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int m,k,n, temp;
		scanf("%d %d %d",&n,&m,&k);

		vector<int> v;
		set<int> ignored;
		set<int> tracked;
		set<int> universal;

		for(int i = 0; i < m; i ++) {
			scanf("%d",&temp);
			ignored.insert(temp);
			universal.insert(temp);
		}

		for(int i = 0; i < k; i ++) {
			scanf("%d",&temp);
			tracked.insert(temp);
			universal.insert(temp);
		}

		set_intersection(ignored.begin(),ignored.end(),tracked.begin(),tracked.end(), back_inserter(v));

		printf("%ld %ld\n",v.size(), n-universal.size());
 
	}

	return 0;
}
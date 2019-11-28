#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		scanf("%d",&n);
		vector<int> v;
		set<int> s;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		s.insert(v[0]);
		for(int i = 1; i < n; i ++) {
			if(v[i] > v[i-1])
				v[i] = v[i-1];

			s.insert(v[i]);
		}
		printf("%ld\n",s.size());
	}
	return 0;
}
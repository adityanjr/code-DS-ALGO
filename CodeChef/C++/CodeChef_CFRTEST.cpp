#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		scanf("%d",&n);
		set<int> s;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			s.insert(temp);
		}

		printf("%ld\n",s.size());
	}
}
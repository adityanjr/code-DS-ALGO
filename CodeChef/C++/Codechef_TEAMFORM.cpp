#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int n, m, temp;
		scanf("%d %d",&n,&m);

		set<int> s;

		for(int i = 0; i < 2*m; i ++) {
			scanf("%d",&temp);
			s.insert(temp);
		}

		if(n % 2 != 0) {
			printf("no\n");
		}
		else {
			printf("yes\n");
		}
	}

	return 0;
}
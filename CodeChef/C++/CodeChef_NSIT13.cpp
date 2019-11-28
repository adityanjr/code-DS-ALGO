#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 10;
	while(t--) {
		int n = 10;
		set<int> s;

		while(n --) {
			int temp;
			scanf("%d",&temp);
			temp = (temp % 42);
			s.insert(temp);
		}

		printf("%ld\n", s.size());
	}

	return 0;
}
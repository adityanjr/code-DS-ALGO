#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int total = 0;
		while(n > 0) {
			total += n % 10;
			n /= 10;
		}

		printf("%d\n",total);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, total=1;
		scanf("%d",&n);
		
		for(int i = 1; i <=n; i ++) {
			total *= i;
		}

		printf("%d\n",total);
	}


	return 0;
}
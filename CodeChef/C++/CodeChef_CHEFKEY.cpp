#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, m, c;
		scanf("%d %d %d",&n,&m,&c);

		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(i*j == c)
					printf("%d %d\n",i,j);
			}
		}

	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int m, n;
		scanf("%d %d",&m,&n);

		int val = 1;
		for(int i = min(m,n); i >= 0; i --) {
			if((m % i) == 0 && (n % i) == 0) {
				val = i;
				break;
			}
		}

		printf("%d\n",((m*n)/(val*val)));
	}

	return 0;
}
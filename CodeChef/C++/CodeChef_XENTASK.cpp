#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		int a[n], b[n], total1 = 0, total2 = 0;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&a[i]);
			if(i % 2 == 0)
				total1 += a[i];
			else
				total2 += a[i];
		}

		for(int i = 0; i < n; i ++) {
			scanf("%d",&b[i]);
			if(i % 2 != 0)
				total1 += b[i];
			else
				total2 += b[i];
		}

		printf("%d\n", (total1 > total2 ? total2 : total1) );
	}
}
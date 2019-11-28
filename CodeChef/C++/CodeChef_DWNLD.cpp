#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int n,k;
		scanf("%d %d",&n,&k);
		int t[n],d[n];

		for(int i = 0; i < n; i ++)
			scanf("%d %d",&t[i],&d[i]);

		int cost = 0;

		for(int i = 0; i < n; i ++) {
			if(k > 0) {
				if(k >= t[i]) {
					k = k - t[i];
					t[i] = 0;
				}
				else if(k < t[i]){
					t[i] = t[i] - k;
					k = 0;
					cost += t[i]*d[i];
				}
			}

			else if(k == 0) {
				cost += t[i]*d[i];
				t[i] = 0;
			}
			else if(k < 0)
				printf("Error\n");
		}

		printf("%d\n",cost);

	}

	return 0;
}
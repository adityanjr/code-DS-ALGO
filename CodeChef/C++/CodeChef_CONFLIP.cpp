#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;
	scanf("%d",&t);

	while(t--) {
		int g;
		scanf("%d",&g);

		/*
		* Heads -> 0
		* Tails -> 1
		*/
		while(g--) {
			long long int n, i, q;
			scanf("%lld %lld %lld",&i,&n,&q);

			long long int count_heads = 0, count_tails = 0;
			
			/*Step 1*/
				if(i == 1) {
					count_heads = n;

					if(n % 2 == 1) {
						count_heads = n/2;
						count_tails = n/2 + 1;						
					}
					else if(n % 2 == 0) {
						count_heads = n/2;
						count_tails = n/2;
					}
				}
				else if(i == 2) {
					count_tails = n;

					if(n % 2 == 1) {
						count_heads = n/2 + 1;
						count_tails = n/2;
					}
					else if(n % 2 == 0) {
						count_heads = n/2;
						count_tails = n/2;
					}
				}

			/*Step 2*/
				if(q == 1)
					printf("%lld\n",count_heads);
				else if(q == 2)
					printf("%lld\n",count_tails);
		}
	}

	return 0;
}
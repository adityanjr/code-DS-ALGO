#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n, m;
	scanf("%lld %lld",&n,&m);

	long long int min = n+2;
	long long int max = 3*n;

	while(m--) {
		long long int q;
		scanf("%lld",&q);

		if(q >= min && q <= max) {
			if(q <= (min+max)/2)
				printf("%lld\n", q-min+1);
			else
				printf("%lld\n",max-q+1);
		}
		else
			printf("0\n");
	}

	return 0;
}
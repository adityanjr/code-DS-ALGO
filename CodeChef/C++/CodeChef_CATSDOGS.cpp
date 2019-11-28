#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int c, d, l;
		scanf("%lld %lld %lld",&c,&d,&l);
		long long int min, max;

		if(c <= 2*d)
			min = d*4;
		else
			min = d*4 + (c-2*d)*4;

		max = (d+c)*4;

		if(l >= min && l <= max && (l%4) == 0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int l, d, s, c, likes;
		scanf("%lld %lld %lld %lld",&l,&d,&s,&c);

		// int likes = s;
		// for(int i = 1; i < d; i ++) {
		// 	printf("%d ",likes );
		// 	likes = likes + likes*c;
		// }
		// printf("\n");

		likes = (s+1)*(pow((c+1),(d-1)));
		printf("%lld\n",likes);

		if(likes >= l)
			printf("ALIVE AND KICKING\n");
		else 
			printf("DEAD AND ROTTING\n");
	}

	return 0;
}

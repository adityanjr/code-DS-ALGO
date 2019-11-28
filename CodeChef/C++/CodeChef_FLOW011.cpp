#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t --) {
		double n;
		scanf("%lf",&n);
		if(n < 1500)
			printf("%.6g\n",n+0.1*n+0.9*n);
		else
			printf("%.6g\n",n+500+0.98*n);
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		int q,p;
		scanf("%d %d",&q,&p);

		if(q > 1000)
			printf("%f\n",0.9*q*p);
		else {
			printf("%f\n",(float)q*p);
		}
	}

	return 0;
}
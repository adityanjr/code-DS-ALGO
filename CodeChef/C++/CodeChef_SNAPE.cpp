#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		float b, ls;
		scanf("%f %f",&b,&ls);

		float max = sqrt(pow(ls,2) + pow(b,2));
		float min = sqrt(pow(ls,2) - pow(b, 2));

		printf("%.4f %.4f\n",min, max);

	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, count = 0;
	scanf("%d",&n);

	while(n--) {
		float x1, x2, x3;
		float y1, y2, y3;
		float m1, m2, m3;

		scanf("%f %f",&x1,&y1);
		scanf("%f %f",&x2,&y2);
		scanf("%f %f",&x3,&y3);

		m1 = ((y2-y1)/(x2-x1));
		m2 = ((y2-y3)/(x2-x3));
		m3 = ((y3-y1)/(x3-x1));

		printf("%f %f %f\n",m1,m2,m3 );

		if(m1*m2 == -1 || m2*m3 == -1 || m1*m3 == -1)
			count++;
	}

	printf("%d\n",count);

	return 0;
}
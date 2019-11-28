#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--) {
		double s, sg, fg, d, t;
		scanf("%lf %lf %lf %lf %lf",&s,&sg,&fg,&d,&t);
		
		double dist = d*50;
		dist = dist/1000;
		
		double time = t/(3600);
		
		double speed = dist/time;
		speed += s;
		
		if(abs(speed-sg) > abs(speed-fg))
			printf("FATHER\n");
		else if(abs(speed-sg) < abs(speed-fg))
			printf("SEBI\n");
		else
			printf("DRAW\n");
	}
	
	return 0;
}

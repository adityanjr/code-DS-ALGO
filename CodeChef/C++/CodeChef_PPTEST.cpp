#include <bits/stdc++.h>
using namespace std;

struct Polo {
	int c, p, t;
};

bool comp(Polo a, Polo b) {
	return (a.t < b.t);
}

int main() {
	int x;
	scanf("%d",&x);
	while(x--) {
		int n, w;
		scanf("%d %d",&n, &w);

		Polo polo[n];
		for(int i = 0; i < n; i ++) {
			scanf("%d %d %d",&polo[i].c, &polo[i].p, &polo[i].t);
		}  

		sort(polo, polo+n, comp);

		int count = 0;
		int time = 0;
		int points = 0;
		while(count < n && time <= w) {
			time += polo[count].t;
			if(time <= w) {
				points += (polo[count].c * polo[count].p);
			}
			count ++;
		}

		printf("%d\n",points);

	}
}
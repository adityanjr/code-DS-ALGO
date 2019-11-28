#include <bits/stdc++.h>
using namespace std;

struct Saree{
	int min, max, p;
};

bool comp(Saree a, Saree b) {
	return (a.p < b.p);
}

int main() {
	int n, m, cost = 0;
	scanf("%d %d",&n,&m);

	Saree s[m];
	for(int i = 0; i < m; i ++) {
		scanf("%d %d %d",&s[i].min, &s[i].max, &s[i].p);
	}

	sort(s, s+m, comp);

	for(int i = 0; i < m; i ++) {
		// printf("%d %d %d\n",s[i].min, s[i].max, s[i].p);
		n -= s[i].min;
		cost += (s[i].min * s[i].p);
	}

	for(int i = 0; i < m; i ++) {
		
	}

	return 0;
}
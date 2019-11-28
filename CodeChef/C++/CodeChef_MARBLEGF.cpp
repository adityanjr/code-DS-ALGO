#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q, temp;
	scanf("%d %d",&n,&q);
	vector<int> v;

	for(int i = 0; i < n; i ++) {
		scanf("%d",&temp);
		v.push_back(temp);
	}

	while(q--) {
		char s;
		int i, j;

		getchar();
		scanf("%c %d %d",&s,&i,&j);

		if(s == 'S') {
			int sum = 0;
			for(int k = i; k <= j; k ++) {
				sum += v[k];
			}
			printf("%d\n",sum );
		}
		else if(s == 'G') {
			v[i] += j;
		}
		else if(s == 'T') {
			v[i] -= j;
		}
	}

	return 0;
}
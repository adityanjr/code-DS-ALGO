#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int M, x, y, temp;
		set<int> s;
		scanf("%d %d %d",&M,&x,&y);

		for(int i = 0; i < M; i ++) {
			scanf("%d",&temp);
			s.insert(temp);
		}

		for(set<int>::iterator it=s.begin(); it != s.end(); ++it) {
			temp = (int)(*it);
			while(temp >= 0)
		}
		printf("\n");
	}

	return 0;
}
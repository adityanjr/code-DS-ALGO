#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		vector< vector<int> > v(n);
		for(int i = 0; i < n; i ++) {
			for(j = 0; j <= i; j ++) {
				int temp;
				scanf("%d",&temp);
				v[i].push_back(temp);
			}
		}

		int sum = 0;
		for(int i = 0; i < n ; i ++) {
			
		}
	}
}
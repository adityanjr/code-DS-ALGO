#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scanf("%d",&t);

	while(t--) {
		int n;
		scanf("%d",&n);

		vector<int> v;

		for(int i = 0; i < n; i ++)
			v[i] = i;

		for(int i = 0; i < log2((double)n); i ++) {

			for(int j = 0; j < n; j ++) {
				if(j % 2 == 0)
					v[j] = 1;
			}

			for(int j = 0; j < n; j ++) {
				if(v[j] == 1)
					myvector.erase (myvector.begin()+j);
			}
		}

	}

	return 0;
}
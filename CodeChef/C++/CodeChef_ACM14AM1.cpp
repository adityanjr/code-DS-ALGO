#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, p, temp;
		scanf("%d %d",&n,&p);

		vector<int> v;

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		temp = 0;
		for(int i = 0; i < n; i ++) {
			if(v[i] < p) {
				i++;
			}
			else {
				temp = i+1;
			}
		}

		printf("%d\n",(temp));
	}
}
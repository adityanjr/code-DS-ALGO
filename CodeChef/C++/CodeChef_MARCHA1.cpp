#include <bits/stdc++.h>
using namespace std;
vector<int> v;

bool count(int n, int m) {
	if(n < 0)
		return false;
	if(m < 0)
		return false;
	if(m == 0)
		return true;
	if(n == 0) {
		if(m==v[0])
			return true;
		return false;
	}
	return count(n - 1, m) | count(n-1, m-v[n]); 
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		v.clear();
		int n, m, temp;
		scanf("%d%d",&n,&m);

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}

		
		if(count(n-1, m))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
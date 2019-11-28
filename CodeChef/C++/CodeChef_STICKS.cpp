#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--) {
		int n, temp;
		vector<int> v;
		map<int, int> m;
		scanf("%d",&n);

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
			if ( m.find(temp) == m.end() ) {
				// not found
				m[temp] = 1;
			} 
			else {
				// found
				m[temp]++;
			}
		}

		sort(v.begin(), v.end());

		int count1 = 0;
		int count2 = 0; 

		for(int i = n - 1; i >= 0; i --) {
			if(m[v[i]] > 3 && count1 == 0) {
				count1 = v[i];
				count2 = v[i];
				i = 0;
			}
			else if(m[v[i]] >= 2 && count1 == 0) {
				count1 = v[i];
				i--;
			}
			else if(m[v[i]] >= 2 && count2 == 0)
				count2 = v[i];
		}

		if(!count1 || !count2)
			printf("-1\n");
		else {
			printf("%d\n",(count1*count2));
		}
	}
}
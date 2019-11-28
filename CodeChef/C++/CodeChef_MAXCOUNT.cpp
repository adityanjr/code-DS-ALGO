#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		vector<int> v;
		int temp;
		map<int, int> m;

		// for(int i = 0; i < n; i ++) {
		// 	scanf("%d",&n);
		// 	v.push_back(temp);
		// }

		// for(int i = 0; i < n; i ++){
		// 	m[v[i]] ++;
		// }

		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			if ( m.find(temp) == m.end() ) {
				// not found
				m[temp] = 1;
			} 
			else {
				// found
				m[temp] += 1;
			}
		}

		int max = INT_MIN;
		for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it) {
    		if(it->second > max) {
    			temp = it -> first;
    			max = it -> second;
    		}
		}

    	printf("%d %d\n",temp,max);
    	}

    return 0;
}
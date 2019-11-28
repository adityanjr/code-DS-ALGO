#include <bits/stdc++.h>
#include <algorithm>    // std::is_sorted, std::prev_permutation
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp, flag = 1;
		vector<int> v;
		scanf("%d",&n);
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);
		}
		
		if(std::is_sorted(v.begin(), v.end())) {
			flag = 0;     
		}
			
		sort(v.begin(), v.end());
		
		for(int i = 0; i < n; i ++) {
			if(v[i] != i+1) {
				flag = 0;
			}
		}
		
		if(!flag)
			printf("no\n");
		else
			printf("yes\n");
	
	} 
	
	return 0;
}

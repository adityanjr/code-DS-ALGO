#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, m, temp, count = 0;
		scanf("%d %d",&n,&m);
		
		vector<int> arr(1000002, 0);
		
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			arr[temp]++;
		}
		
		for(int i = 0; i < m; i ++) {
			scanf("%d",&temp);
			if(arr[temp])
				count++;
		}
		
			
		
		printf("%d\n",count);
	}
	
	return 0;
}

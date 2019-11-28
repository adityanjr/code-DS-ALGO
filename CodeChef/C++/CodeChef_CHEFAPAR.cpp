#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n, temp;
		scanf("%d",&n);
		vector<int> v;
		int flag = 0, count = 0;
		
		for(int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			v.push_back(temp);	
			if(temp == 0)
				flag = 1;
			else 
			count += 1;
		}	
		
		long long int fine = (v.size()*1000);
		
		if(flag) {
			fine += (v.size()*100);
		}
		
		fine -= (count*1000);
		
		printf("%lld\n",fine);
		
	}

	return 0;
}

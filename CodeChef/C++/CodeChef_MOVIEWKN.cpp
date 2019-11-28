#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int l[n],r[n];
	
		for(int i = 0; i < n; i ++)
			scanf("%d",&l[i]);
		
		for(int i = 0; i < n; i ++)
			scanf("%d",&r[i]);

		int count_max = INT_MIN;
		int count_rating = 0;
		int val;

		for(int i = 0; i < n; i ++){
			if(l[i]*r[i] > count_max || (l[i]*r[i] == count_max && r[i] > count_rating)) {
				val = i;
				count_max = l[i]*r[i];
				count_rating = r[i];
			}
		}

		printf("%d\n",val+1);
			
	}

	return 0;
}
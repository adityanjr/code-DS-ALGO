#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int flag[n]={0};
		int count = 0;

		string s;
		cin >> s;


		for(int i = 0; i < n; i ++) {
			if(s[i] == '1') {
				if(i == 0) {
					flag[0] = 1;
					flag[1] = 1;
				}
				else if(i == n - 1) {
					flag[n-2] = 1;
					flag[n-1] = 1;
				}
				else {
					flag[i-1] = 1;
					flag[i] = 1;
					flag[i+1] = 1;
				}

			}
		}

		for(int i = 0; i < n; i ++)
			if (flag[i]==0) 
				count ++;
			
		printf("%d\n",count );
	}

	return 0;
}
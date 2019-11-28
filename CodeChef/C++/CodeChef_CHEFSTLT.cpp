#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s1, s2;

		cin >> s1;
		cin >> s2;

		int count_min = 0, count_max = 0;

		for(int i = 0; i < s1.length(); i ++) {
			if(s1[i]!=s2[i]) {
				if(s1[i] == '?' || s2[i] == '?') {
					count_max++;
				} 
				else {
					count_min++;
					count_max++;
				}
			}
			else if(s1[i] == '?' || s2[i] == '?') {
				count_max ++;
			}
		}

		printf("%d %d\n",count_min,count_max);
	}

	return 0;
}
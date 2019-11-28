#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;
		int count_0=0, count_1=0;

		for(int i = 0; s[i] != '\0'; i ++) {
			if(s[i] == '0')
				count_0++;
			else if(s[i] == '1')
				count_1++;
		}

		if(count_0 == 1 || count_1 == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
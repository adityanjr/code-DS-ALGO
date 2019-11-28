#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;
		int count = 0;

		// int temp = 'a';
		// printf("%d\n", temp);
		for(int i = 0; i < s.size(); i ++) {
			int temp = s[i];
			count += (temp - 97);
		}

		printf("%d\n",count );

		if((11*(s.size())) > count)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
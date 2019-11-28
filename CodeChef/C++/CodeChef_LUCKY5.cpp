#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;
		int count = 0;

		for(int i = 0; i < s.size(); i ++) {
			if(s[i] != '4' && s[i] != '7')
				count ++;
		}

		printf("%d\n",count );

	}

	return 0;
}
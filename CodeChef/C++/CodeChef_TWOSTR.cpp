#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		string s1, s2;

		cin >> s1;
		cin >> s2;
	
		int flag = 1;
		for(int i = 0; i < s1.length(); i ++) {
			if(s1[i]!=s2[i] && s1[i]!= '?' && s2[i] != '?')
				flag = 0;
		}

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
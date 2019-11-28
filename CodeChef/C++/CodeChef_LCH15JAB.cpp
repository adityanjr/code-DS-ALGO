#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);

	while(t --) {
		string s;
		cin >> s;

		map<char, int> m;

		int max = 1;

		for(int i = 0; i < s.size(); i ++) {
			if(m.find(s[i]) == m.end()) {
				//Not found
				m[s[i]] = 1;
			}
			else {
				m[s[i]]++;
				if(m[s[i]] > max)
					max = m[s[i]];
			}
		}

		if(max == s.size()-max)
			printf("YES\n");
		else 
			printf("NO\n");
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);

		string s;
		cin >> s;

		map<char, int> m;
		m['R'] = 0;
		m['G'] = 0;
		m['B'] = 0;

		for(int i = 0; i < s.size(); i ++) {
			m[s[i]]++;
		}

		printf("%d\n",(n-max(m['R'], max(m['G'], m['B']))) );
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string str;
	cin >> t >> str;

	map<char, char> m;
	for(int i = 0; i < str.size(); i ++) {
		m[(char)('a' + i)] = str[i];
		m[(char)('A' + i)] = (char)(str[i]-32);
	}

	m['_'] = ' ';
	m['?'] = '?';
	m['!'] = '!';
	m['.'] = '.';
	m[','] = ',';

	while(t--) {
		string s;
		cin >> s;

		for(int i = 0; i < s.size(); i ++) {
			cout << m[s[i]];
		}
		cout << "\n";
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, str = "";
	cin >> s;
	map<char, int> m;
	
	for(int i = 0; i < s.size(); i ++) {
		if(m.find(s[i]) == m.end()) {
			m[s[i]] = 1;
		}
		else {
			m[s[i]] += 1;
		}
	}

	int j = 0;
	for(int i = 0; i < s.size(); i ++) {
		size_t found = str.find(s[i]);
  		if (found == string::npos)
    		str += s[i];
	}

	for(int i = 0; i < str.size(); i ++) {
		cout << str[i] << m[str[i]];
	}
	printf("\n");

	return 0;
}
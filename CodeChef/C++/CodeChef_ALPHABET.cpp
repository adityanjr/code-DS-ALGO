#include <bits/stdc++.h>
using namespace std;
int main() {
	
	/* code */
	string s;
	cin >> s;
	map<char, int> map;

	for(int i = 0; i < 26; i ++) {
		map['a'+i] = 0;
	}

	for(int i = 0; i < s.size(); i ++) {
		map[s[i]]++;
	}

	int n;
	scanf("%d",&n);
	while(n--) {
		string str;
		cin >> str;

		int flag = 1;
		for(int i = 0; i < str.size(); i ++) {
			if(map[str[i]] == 0)
				flag = 0;
		}

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}	

	return 0;
}
#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int count = 0;
		string j, s;
		cin >> j;
		cin >> s;

		set<char> set1;

		for(int i = 0; i < j.size(); i ++) {
			set1.insert(j[i]);
		}

		for(int i = 0; i < s.size(); i ++) {
			if(set1.find(s[i]) != set1.end())
				count++;
		}

		printf("%d\n",count);
	}

	return 0;
}
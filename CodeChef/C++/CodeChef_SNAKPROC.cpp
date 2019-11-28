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
		char val = 'H';
		int flag = 1;

		for(int i = 0; i < s.size(); i ++) {
			if(s[i] == '.') {
				continue;
			}
			else if(s[i] == val) {
				if(val == 'H') {
					val = 'T';
				}
				else if(val == 'T') {
					val = 'H';
				}
			}
			else if(s[i] != val) {
				flag = 0;
			}
		}

		if(flag && val == 'H') {
			printf("Valid\n");
		}
		else {
			printf("Invalid\n");
		}
	}

	return 0;
}
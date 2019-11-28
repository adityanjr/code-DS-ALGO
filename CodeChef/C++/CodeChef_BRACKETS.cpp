#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;

		int balance = 0;
		int max_balance = 0;

		for(int i = 0; i < s.length(); i ++) {
			if(s[i] == '(') {
				balance++;
			}
			else if(s[i] == ')') {
				balance --;
			}
			max_balance = max(max_balance, balance);
		}

		for(int i = 0; i < max_balance; i ++)
			printf("(");
		for(int i = 0; i < max_balance; i ++)
			printf(")");
		printf("\n");
	}

	return 0;
}
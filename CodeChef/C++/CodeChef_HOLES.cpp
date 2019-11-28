#include <bits/stdc++.h>

using namespace std;

int main(){

	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;

		int count = 0;

		for(int i = 0; i < s.length(); i++) {
			if(s[i]== 'B')
				count += 2;
			else if(s[i] == 'A' || s[i] == 'D' || s[i] == 'O')
				count++;
			else if(s[i] == 'P' || s[i] == 'Q' || s[i] == 'R')
				count++;
		}

		printf("%d\n",count);
	}

	return 0;
} 
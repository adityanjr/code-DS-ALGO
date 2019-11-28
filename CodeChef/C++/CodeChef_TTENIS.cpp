#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;

		int chef = 0, opp = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '1')
				chef++;
			else 
				opp++;
		} 

		if(chef > opp)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
}
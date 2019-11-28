#include <bits/stdc++.h>
using namespace std;

int score(int x, int y) {
	if(abs(x-y) == 1 || abs(x-y) == 0)
		return 0;

	return (abs(x-y)+1);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int count = 0;
		string s;
		vector<int> v;
		cin >> s;

		// for(int i = 0; i < s.size(); i ++) {
		// 	if(s[i] == '1') {
		// 		v.push_back(i);
		// 	}
		// }

		int ones = 0;

		for(int  i = s.size()-1; i >= 0; i --) {
			if(s[i] == '1') {
				count += (score(i, s.size()-ones-1));
				// printf("%lld->", count);
				ones++;
			}
		}

		printf("%lld\n",count);
		
	}



	return 0;
}
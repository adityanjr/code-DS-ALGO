#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long int n, count  = 0;
		scanf("%lld",&n);

		string s;
		cin >> s;

		for(long long int i = 0; i < s.size(); i ++) {
			if(s[i] == '1')
				count ++;
		}

		printf("%lld\n", ((count*(count+1))/2));
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		map<string, string> m;

		string name, sign;
		for(int i = 0; i < n; i++) {
			cin >> name; 
			cin >> sign;
			if ( m.find(name) == m.end() ) {
				// not found
				m[name] = sign;
			} 
			else {
				// found
				m[name] = sign;
			}
		}

		int count = 0;
		for(map<string, string>::iterator it = m.begin(); it != m.end(); ++it) {
			sign = (*it).second;
			if(sign == "+")
				count++;
			else if(sign == "-")
				count --;
		}

		printf("%d\n",count);
	}

	return 0;
}
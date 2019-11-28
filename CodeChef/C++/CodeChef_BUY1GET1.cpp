#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int count = 0;
		string s;
		cin >> s;
		map<char, int> m;

		for(int i = 0; i < s.size(); i ++) {
			if ( m.find(s[i]) == m.end() ) {
				// not found
				m[s[i]] = 1;
			} 
			else {
				// found
				m[s[i]] += 1;
			}
		}

		for(map<char, int>::iterator it=m.begin(); it!=m.end(); ++it) {
			if(it->second == 1) {
				count += 1;
			}
			else if(it->second%2 == 0){
				count += (it->second/2);
			}
			else if(it->second % 2 != 0){
				count += ((it->second/2)+1);
			}
		}

		printf("%d\n",count);
	}

}
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int count_c = 0, count_h = 0, count_e = 0, count_f = 0;
	for(int i = 0; i < s.length(); i ++) {
		if(s[i] == 'C')
			count_c++;
		else if(s[i] == 'H')
			count_h++;
		else if(s[i] == 'E')
			count_e++;
		else if(s[i] == 'F')
			count_f++;
	}

	printf("%d\n",min(min(count_c, count_h), min(count_e, count_f)));

	return 0;
}
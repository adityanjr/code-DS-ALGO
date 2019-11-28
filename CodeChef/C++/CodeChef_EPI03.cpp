#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	char c;
	int count = 0;

	cin >> s;
	cin >> c;

	for(int i = 0; i < s.length(); i ++)
		if(s[i] == c)
			count++;

	printf("%d\n",count);	

	return 0;
}
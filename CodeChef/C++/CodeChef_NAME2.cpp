#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string str1, str2;
		cin >> str1 >> str2;
		int flag = 0;

		if(str1.size() <= str2.size()) {
			for(int i = 0, j = 0; j < str2.size(); j ++) {
				if(str1[i] == str2[j]) {
					i ++;
				}

				if(i == (str1.size())) {
					flag = 1;
				}
			}
		}
		else {
			for(int i = 0, j = 0; j < str1.size(); j ++) {
				if(str2[i] == str1[j]) {
					i ++;
				}

				if(i == (str2.size())) {
					flag = 1;
				}
			}
		}

		
		if(flag) 
			printf("YES\n");
		else 
			printf("NO\n");
	}

	return 0;
}
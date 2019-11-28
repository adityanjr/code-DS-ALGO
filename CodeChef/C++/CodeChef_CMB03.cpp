#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string a, b;
		cin >> a;
		cin >> b;
		int flag = 0;

		for(int i = 0; i < a.size(); i ++) {
			if(a[i] == b[0]) {
				flag = 1;
				for(int j = 1; j < b.size(); j ++) {
					if(a[i+j] != b[j])
						flag = 0;
				}
			}
			if(flag)
				break;
		}

		if(flag)
			printf("1\n");
		else
			printf("0\n");
	}
}
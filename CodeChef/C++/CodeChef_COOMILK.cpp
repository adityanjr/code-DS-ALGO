#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--) {
		int n, flag = 1;
		scanf("%d",&n);
		
		vector<string> v;
		string temp;
		
		for(int i = 0; i < n; i ++) {
			cin >> temp;
			v.push_back(temp);
		}
		v.push_back("salman");
		
		for(int i = 0; i < n; i ++) {
			if(v[i] == "cookie") {
				if(v[i+1] != "milk") {
					flag = 0;
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

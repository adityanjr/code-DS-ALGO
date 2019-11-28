#include <bits/stdc++.h>
using namespace std;

int commonParent(int x, int y) {
	set<int> s;

		while(x > 0) {
			s.insert(x);
			x/=2;
		}

		int flag = 1;
		while(y > 0 && flag) {
			if(s.find(y) == s.end()) {
				//Not found
				y /= 2;
			}
			else {
				//Found
				return y;
				flag=0;
			}
		}
	return 1;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x, y;
		scanf("%d %d",&x,&y);
		
		int parent = commonParent(x, y);

		int count = 0;
		while(x != parent) {
			x/=2;
			count++;
		}

		while(y != parent) {
			y/=2;
			count++;
		}

		printf("%d\n",count);
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x1, y1;
		int x2, y2;

		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

		if(((x1-x2) == 0) && ((y1-y2) != 0)) {
			if(y1 < y2) {
				printf("up\n");
			}
			else
				printf("down\n");
		}
		else if(((y1-y2) == 0) && ((x1-x2) != 0)) {
			if(x1 < x2) {
				printf("right\n");
			}
			else {
				printf("left\n");
			}
		}
		else {
			printf("sad\n");
		}
	}

	return 0;
}
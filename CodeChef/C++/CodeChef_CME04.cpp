#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int l_room, b_room;
		int l_tile, b_tile;

		scanf("%d %d %d %d",&l_room,&b_room,&l_tile,&b_tile);

		if(((l_room*b_room) % (l_tile*b_tile)) == 0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
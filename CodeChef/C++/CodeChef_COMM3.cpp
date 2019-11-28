#include <bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {
	double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	return dist;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int r;
		scanf("%d",&r);
		int chef_x, chef_y;
		scanf("%d %d",&chef_x,&chef_y);
		int server_x, server_y;
		scanf("%d %d",&server_x,&server_y);
		int sous_x, sous_y;
		scanf("%d %d",&sous_x,&sous_y);

		int flag = 0;
		if(dist(chef_x, chef_y, sous_x, sous_y) <= r) {
			printf("yes\n");
		}
		else if((dist(chef_x, chef_y, server_x, server_y) <= r ) && dist(server_x, server_y, sous_x, sous_y) <= r)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
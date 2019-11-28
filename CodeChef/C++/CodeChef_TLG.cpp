#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d",&n);

	int max1 = 0, max2 = 0;
	int score1 = 0, score2 = 0;
	for(int i = 0; i < n; i ++) {
		int temp1, temp2;
		scanf("%d %d",&temp1,&temp2);

		score1 += temp1;
		score2 += temp2;

		if(max1 < score1 - score2) {
			max1 = score1 - score2;
		}
		else if(max2 < score2 - score1) {
			max2 = score2 - score1;
		}
	}

	if(max1 > max2)
		printf("1 %d", max1);
	else 
		printf("2 %d",max2);

}
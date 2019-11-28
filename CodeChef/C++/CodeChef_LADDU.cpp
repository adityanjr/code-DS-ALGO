#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x;
		string nation;
		cin >> x >> nation;
		int score = 0;

		while(x--) {
			string activity;
			cin >> activity;

			if(activity == "CONTEST_WON"){
				int rank;
				cin >> rank;

				if(rank < 20) {
					score += (300 + (20-rank));
				}
				else {
					score += 300;
				}
			}
			else if(activity == "TOP_CONTRIBUTOR") {
				score += 300;
			}
			else if (activity == "BUG_FOUND") {
				int bug_score;
				cin >> bug_score;
				score += bug_score;
			}
			else if(activity == "CONTEST_HOSTED"){
				score += 50;
			}

		}

		if(nation == "INDIAN") {
			printf("%d\n",(score/200));
		}
		else {
			printf("%d\n",(score/400));
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	scand("%d",&t);
	while(t--) {
		int n;
		string cont, chef;
		cin >> cont;
		cin >> chef;

		int score[n+1];
		for(int i = 0; i <= n; i ++)
			scanf("%d",&score[i]);
		vector<int> v(score,score+n+1);

		int max_correct = 0;

		for(int i = 0; i < cont.length(); i ++) {
			if(cont[i] == chef[i])
				max_correct++;
		}

		

	}

	return 0;
}
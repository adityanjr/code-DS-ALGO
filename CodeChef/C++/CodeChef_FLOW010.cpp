#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string x;
		
		cin >> x;
		// cout << x << endl;

		if(x == "B" || x == "b")
			printf("BattleShip\n");
		else if(x == "C" || x == "c")
			printf("Cruiser\n");
		else if(x == "D" || x == "d")
			printf("Destroyer\n");
		else if(x == "F" || x == "f")
			printf("Frigate\n");
	}

	return 0;
}
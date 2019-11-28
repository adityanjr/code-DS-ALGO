#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {

		string y,x,z;
		cin >> x;
		cin >> y;

		z = "";

		for(int i = 0; i < x.size(); i ++) {
			if(x[i] == 'W' && y[i] == 'W')
				z += 'B';
			else if(x[i] == 'B' && y[i] == 'B')
				z += 'W';
			else
				z += 'B';
		}
		cout << z << "\n";

	}

	return 0;
}
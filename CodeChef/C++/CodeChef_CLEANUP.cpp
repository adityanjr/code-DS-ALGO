#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n,m;

		scanf("%d %d",&n,&m);
		bool arr[n] = {};

		for(int i = 0; i < m; i ++) {
			int temp;			
			scanf("%d",&temp);
			arr[temp-1] = true;
		}

		int count = 0;
		int chef[n/2], assistant[n/2], temp[n];

		for(int i = 0; i < n; i ++)
			if(arr[i] == 0)
				temp[count++]=i+1;

		int i = 0, a = 0, b = 0;
		while(i < count) {
			chef[a++] = temp[i++];
			if(i < count)
				assistant[b++] = temp[i++]; 
		}

		for(i = 0; i < a; i ++)
			cout << chef[i] << " ";
		cout << endl;

		for(i = 0; i < b; i ++)
			cout << assistant[i] << " ";
		cout << endl;

	}

	return 0;
}
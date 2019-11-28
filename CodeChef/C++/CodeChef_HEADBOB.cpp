#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		
		string obs;
		cin >> obs;
	
		int count_y=0, count_n=0, count_i=0;
		for(int i = 0; i < n; i ++) {
			if(obs[i] == 'Y') 
				count_y++;
			if(obs[i] == 'I')
				count_i++;
			if(obs[i] == 'N')
				count_n++;
		}

		if(count_y > 0)
			printf("NOT INDIAN\n");
		else if(count_i > 0)
			printf("INDIAN\n");
		else
			printf("NOT SURE\n");
	}
	return 0;
}
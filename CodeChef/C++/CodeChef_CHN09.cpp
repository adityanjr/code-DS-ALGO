#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		string s;
		cin >> s;

		int count_a = 0, count_b = 0;

		for(int i = 0; s[i] != '\0'; i ++){
			if(s[i] == 'a')
				count_a++;
			else if(s[i] == 'b')
				count_b++;
		}

		if(count_a == 0 || count_b == 0)
			printf("0\n");
		else if(count_a < count_b) 
			printf("%d\n",count_a);
		else if(count_b < count_a)
			printf("%d\n",count_b);
		else if( count_a == count_b)
			printf("%d\n",count_a);
		
	}
}
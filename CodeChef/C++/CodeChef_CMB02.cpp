#include <bits/stdc++.h>

using namespace std;

bool palindrome(int n) {
	

	int temp = 0, rem, orig = n, i = 0;
	while(n > 0) {
		rem = n % 10;
		temp = temp*10 + rem;
		n = n / 10;
		i ++; 
	}

	if(orig == temp)
		return true;
	return false;
}

int main() {

	int t;
	scanf("%d",&t);
	while(t--) {
		int pal,n;
		cin >> n;
		int flag = 1;
		n++;

		while(flag) {
			if(palindrome(n)) {
				printf("%d\n",n);
				flag = 0;
			}
			else {
				n++;
			}

		}


	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int Gcd(int n1, int n2) {
	while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }

    return n1;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d %d",&a,&b);
	
		int gcd = Gcd(a,b);
		int lcm = ((a*b)/gcd);
	
		printf("%d %d\n",gcd, lcm);
	}

	return 0;
}
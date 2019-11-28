#include <bits/stdc++.h>
using namespace std;

int temp;

bool isPrime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return false;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return false;
    }
    return true;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int x, y, z, flag = 0;
		scanf("%d %d",&x,&y);

		temp = x + y;
		if(temp%2 == 0)
			temp++;
		else
			temp += 2;
		
		for(int i = temp; flag != 1; i+=2) {
			if(isPrime(i)) {
				flag = 1;
				temp = i;
			}
		}

		printf("%d\n",temp-x-y);

	}

	return 0;
}
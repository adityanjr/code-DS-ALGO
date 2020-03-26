// http://www.geeksforgeeks.org/sieve-of-eratosthenes

#include <iostream>
#include <vector>
using namespace std;

void SieveOfEratosthenes(int n){
	vector<bool> p(n+1, 0);
	for(int i=2; i<n+1; i++){
		int k = 2;
		while(k*i < n+1){
			p[k*i] = 1;
			k++;
		}
	}
	for(int i=2; i<=n; i++){
		if(p[i]==0)
			cout<<i<<" ";
	}
}

int main(){
	int n = 30;
    printf("Following are the prime numbers below %d\n", n);
    SieveOfEratosthenes(n);
	return 0;
}


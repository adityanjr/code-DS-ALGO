// http://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys

#include <bits/stdc++.h>
using namespace std;

int cache[100];

int findoptimal(int N){
	if(cache[N])
		return cache[N];
	int bl; //break point
	for(int n=7; n<=N; n++){
		for(int b = n-3; b>0; b--){
			int cur = (n-b-1)*cache[b];
			cache[n] = max(cache[n], cur);
		}
	}
	return cache[N];
}

int main() {
	memset(cache, 0, sizeof(cache));
	for(int i=0; i<=6; i++)
		cache[i] = i;
    for (int N=1; N<=20; N++)
        printf("Maximum Number of A's with %d keystrokes is %d\n", N, findoptimal(N));
}

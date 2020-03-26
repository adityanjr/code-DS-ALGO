// http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s

#include <bits/stdc++.h>
using namespace std;

int countStrings(int N){
	int cache0[N+1], cache1[N+1];
	cache0[0] = 0;
	cache1[0] = 0;
	cache0[1] = 1;
	cache1[1] = 1;
	for(int i=2; i<=N; i++){
		cache0[i] = cache0[i-1] + cache1[i-1];
		cache1[i] = cache0[i-1];
	}
	return cache0[N] + cache1[N];
}

int main(){
	cout << countStrings(3) << endl;
	return 0;
}


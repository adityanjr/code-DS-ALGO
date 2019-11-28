#include <bits/stdc++.h>
using namespace std;

long long int GCD(long long int a, long long int b) { 
  if ( b == 0 )
    return a;
  return GCD ( b,a%b);
} 

long long int LCM(long long int a, long long int b)  { 
    return a*(b/GCD(a,b)); 

}

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--) {
		long long int n, temp;
		scanf("%lld",&n);
		vector<long long int> v;
		for(int i = 0; i < n; i ++) {
			scanf("%lld",&temp);
			v.push_back(temp);
		}
		
		long long int val = INT_MAX;
		temp = INT_MAX;
		for(int i = 0; i < n; i ++) {
			for(int j = i+1; j < n; j ++) {
				if(i != j)
					temp = LCM(v[i], v[j]);
				if(temp < val)
					val = temp;					
			}
		}
		
		printf("%lld\n",val);
		
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a, int b){
	if (a==0) return b;
	return gcd(b%a, a);
}

int sumN(int n){
	int sum=0;
	f(1,n){
		sum += i;
	}
	return sum;
}

int main(){
	c_p_c();

	t(x){
		int d, n;
		cin>>d>>n;
		while(d--){
			n=sumN(n);
		}
		cout<<n<<endl;
	}

	return 0;
}
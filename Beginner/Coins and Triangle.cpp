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

int main(){
	c_p_c();

	t(x){
		int n;
		cin>>n;
		int height=0, rem=1;;
		while(n>height){
			n = n-rem;
			height++;
			rem++;
		}
		cout<<height<<endl;
	}
	
	return 0;
}

------------------------------------------

int main() {
	int t;
	cin>>t;
	while(t--){
	    long int n;
	    cin>>n;
	    int x = (sqrt(1+(8*n)) - 1)/2;
	    cout<<floor(x)<<endl;
	}
	return 0;
}
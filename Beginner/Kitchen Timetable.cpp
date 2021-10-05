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

	ll a[10005];
	t(x){

		ll n;
		cin>>n;
        f(0,n-1){
            cin>>a[i];
        }
        ll b; int count;
        cin>>b;
        b<=a[0] ? count=1:count=0;
        f(1,n-1){
            cin>>b;
            if(b<=a[i]-a[i-1])
                count++;
        }
        cout<<count<<endl;
	}

	return 0;

}
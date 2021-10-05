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
		ll n;
		cin>>n;
		ll arr[n];
		f(0, n-1) {
			cin >> arr[i];
		}
		ll ans[n]={0};
		ans[n-1] = 1;

		for(int i= n-2; i>=0; i--) {
			if(arr[i]*arr[i+1]<0) {
				ans[i] =ans[i+1]+1;
			}
			else ans[i] =1;
		}
		f(0,n-1) {
			cout << ans[i] << " ";
		}
		cout<<endl;
	}

	return 0;

}
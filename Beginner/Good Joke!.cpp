#include<bits/stdc++.h>
using namespace std;

// Author - ADITYA SINGH (https://github.com/adityanjr)

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
		int arr[n][2];
		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				cin>>arr[i][j];
			}
		}
		int xor_res = 0;
		for(int i=1; i<=n; i++){
			xor_res ^= i;
		}
		cout<<xor_res<<endl;
	}

	return 0;

}
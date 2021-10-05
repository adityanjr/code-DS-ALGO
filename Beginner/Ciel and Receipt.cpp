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

    	mk(arr,12);
    	f(0,11){
    		arr[i] = 1<<i;
    	}
    	int p; cin>>p;
    	int res=0;
        for(int i=11;i>=0;i--){
        	res += p/arr[i];
        	p %= arr[i];
        }
        cout<<res<<endl;
    }

	return 0;
}
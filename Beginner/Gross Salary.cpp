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
		ll s; cin>>s;
        float g;
        if(s<1500)
            g=2*s; // basic + (0.1basic + 0.9basic)
        else
            g=s+500+(0.98*s);
        printf("%.2f\n", g);
    }

	return 0;
}
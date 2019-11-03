#include<iostream>
using namespace std;
#define ll long long 

ll binary_search(ll n,ll m, ll x,ll y){
    ll ans=0, l=0, r=n, mid;
    while(l <= r){
	mid = (l + r)/2;
	if((mid * x) <= m + ((n - mid) * y)){
		ans=mid;
		l=mid+1;
	} 
    else
	    r = mid-1;
}
    return ans;
}

int main(){
    ll n, m ,x,y, a[10000000],i;
    cin>>n>>m>>x>>y;
    cout<<binary_search(n,m,x,y);
	return 0;
}
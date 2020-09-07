// Trailing zeros in n factorial
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll ans=0;
    for(ll c=5;n/c>=1;c*=5)
        ans+=n/c;
    cout<<ans;
    return 0;
}

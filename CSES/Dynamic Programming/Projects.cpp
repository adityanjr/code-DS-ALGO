// For each project starting and ending time and it's reward is given.
// Find maximum profit.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (int i = 0; i < n; ++i)
#define forn(i,a,b) for (int i =a; i <=b; ++i)
#define revforn(i,a,b) for (int i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<ll, 3>a[n];
    rep(i, n)
    cin >> a[i][1] >> a[i][0] >> a[i][2];
    sort(a, a + n);
    set<array<ll, 2>>s;
    s.insert({0, 0});
    ll ans = 0;
    rep(i, n)
    {
        auto it = s.lower_bound({a[i][1]});
        --it;
        ans=max(ans,(*it)[1]+a[i][2]);
        s.insert({a[i][0],ans});
    }
    cout<<ans;
    return 0;
}
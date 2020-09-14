// Find the minimum absolute sum of amount to be added or subtracted to make all elements of array equal
// It's optimal to convert to a median value
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (int i = 0; i < n; ++i)
#define forn(i,a,b) for (int i =a; i <b; ++i)
#define revforn(i,a,b) for (int i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    ll x=a[n/2];
    ll ans=0;
    rep(i,n)
    {
        ans+=abs(a[i]-x);
    }
    cout << ans;
    return 0;
}

// derangement permutation
// n!(1-1!+1/2!-1/3!...+-1/n!)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define forn(i,a,b) for (ll i =a; i <=b; ++i)
#define revforn(i,a,b) for (ll i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
const int mxn = 1e6 + 1;
const int mod=1e9+7;
ll dp[mxn];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    forn(i, 3, n)
    dp[i] = ((i - 1) % mod * ((dp[i - 1] + dp[i - 2]) % mod)) % mod;
    cout << dp[n];
}
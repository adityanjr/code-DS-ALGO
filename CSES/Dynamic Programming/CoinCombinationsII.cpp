// Find distinct ordered ways you can produce a money sum x using the available coins
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
const int mod = 1e9 + 7;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int a[n];
    int dp[x + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    rep(i, n)
    cin >> a[i];
    for(int j = 0; j < n; j++)
        for(int i = 1; i <= x; i++)
        {
            {
                if(i - a[j] >= 0)
                {
                    dp[i] = (dp[i] + dp[i - a[j]]) % mod;
                }
            }
        }
    cout << dp[x];
    return 0;
}
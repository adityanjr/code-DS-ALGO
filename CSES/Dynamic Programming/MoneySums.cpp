// Print all possible sums from an array.
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
    int a[n];
    int s = 0, sz = 0;
    rep(i, n)
    cin >> a[i], s += a[i];
    bool dp[n + 1][s + 1];
    memset(dp, 0, sizeof dp);
    rep(i, n + 1)
    dp[i][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][a[i - 1]] = 1;
        for(int j = 1; j <= s; j++)
        {
            if(dp[i - 1][j])
            {
                dp[i][j] = 1;
                dp[i][j + a[i - 1]] = 1;
            }
        }
    }
    rep(j, s + 1)
    if(j)
        sz += (dp[n][j] == 1);
    cout << sz << '\n';
    rep(j, s + 1)
    {
        if(j && dp[n][j])
        {
            cout << j << " ";
        }
    }
    return 0;
}

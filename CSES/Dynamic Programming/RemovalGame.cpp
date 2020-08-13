// Remove first or last element from a list, print maximum score for both players.
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
    ll a[n];
    rep(i, n)
    cin >> a[i];
    array<ll, 2>dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int i = n - 1; ~i; --i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            array<ll, 2>tr;
            if(dp[i + 1][j][1] + a[i] > dp[i][j - 1][1] + a[j])
                tr = {dp[i + 1][j][1] + a[i], dp[i + 1][j][0]};
            else
                tr = {dp[i][j - 1][1] + a[j], dp[i][j - 1][0]};
            dp[i][j] = tr;
        }
    }
    cout << dp[0][n - 1][0];
    return 0;
}
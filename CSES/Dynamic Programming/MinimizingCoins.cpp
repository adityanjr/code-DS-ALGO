// Given money denominations find minimum number of coins to make the given amount if possible
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
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int a[n];
    int dp[x + 1];
    dp[0] = 0;
    rep(i, n)
    cin >> a[i];
    sort(a,a+n);
    for(int i = 1; i <= x; i++)
    {
        dp[i] = -1;
        int coins = 1e9;
        for(int j = 0; j < n && i - a[j] >= 0; j++)
        {
            if(dp[i - a[j]] >= 0)
                coins = min(coins, dp[i - a[j]] + 1);
        }
        if(coins != 1e9)
            dp[i] = coins;
    }
    cout<<dp[x];
    return 0;
}
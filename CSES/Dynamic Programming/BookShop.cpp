// Classic Knapsack Problem
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
    int cost[n], profit[n];
    rep(i, n)
    cin >> cost[i];
    rep(i, n)
    cin >> profit[i];
    int dp[x + 1];
    memset(dp,0,sizeof dp);
    rep(i,n)
    {
        for(int j=x;j>=cost[i];--j)
        {
            dp[j]=max(dp[j],dp[j-cost[i]]+profit[i]);
        }
    }
    cout<<dp[x];
    return 0;
}
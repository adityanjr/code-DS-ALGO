// Find the number of ways a given number can be made using any number of dices
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
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=min(6,i);j++)
        {
            dp[i]=(dp[i]+dp[i-j])%mod;
        }
    }
    cout<<dp[n];
    return 0;
}
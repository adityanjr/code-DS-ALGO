// Find number of valid grid paths.
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
template<typename T>
inline T add(T a, T b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
template<typename T>
inline T sub(T a, T b)
{
    a -= b;
    if (a < 0) a += mod;
    return a;
}
template<typename T>
inline T mul(T a, T b)
{
    return  (a * b % mod);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s[n];
    rep(i, n)
    cin >> s[i];
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    dp[0][0]=(s[0][0]=='.');
    for(int i=1;i<n;i++)
    {
        dp[0][i]=(dp[0][i-1]&&s[0][i]=='.');
    }
    for(int i=1;i<n;i++)
    {
        dp[i][0]=(dp[i-1][0]&&s[i][0]=='.');
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s[i][j]!='*')
            dp[i][j]=add(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
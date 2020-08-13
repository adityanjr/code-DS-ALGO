// Given axb rectangle, determine minimum cuts to make all resulting quadrilaterals to be squares.
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
    int a, b;
    cin >> a >> b;
    int dp[a + 1][b + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(i ^ j)
                dp[i][j] = 1e9;
            // ixj rectangle as kxj rectangle + (i-k)xj rectangle
            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            // ixj rectangle as ixk rectangle + ix(j-k) rectangle
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }
    cout << dp[a][b];
    return 0;
}
// probability of getting sum in range [a,b] after throwing dice n times
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
    cin.tie(0);
    int n;
    cin >> n;
    ld dp[n + 1][6 * n + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= 6 * i; j++)
        {
            for(int k = 1; k <= min(6, j); ++k)
            {
                dp[i][j] += dp[i - 1][j - k] / 6;
            }
        }
    }
    int a, b;
    cin >> a >> b;
    ld ans = 0;
    for(int i = a; i <= b; i++)
        ans += dp[n][i];
    cout << fixed << setprecision(6) << ans;
    return 0;
}
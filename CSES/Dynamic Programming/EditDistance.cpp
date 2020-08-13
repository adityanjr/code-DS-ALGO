// Minimum operation to calculate the operation to make two strings equal
// using removal,replacement and addition of character.
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int dp[s.size() + 1][t.size() + 1];
    forn(i, 0, s.size())
    dp[i][0] = i;
    forn(j, 0, t.size())
    dp[0][j] = j;
    forn(i, 1, s.size())
    {
        forn(j, 1, t.size())
        {
            dp[i][j]=1e9;
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            dp[i][j]=min({dp[i][j]-1,dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
        }
    }
    cout<<dp[s.size()][t.size()];
    return 0;
}
// Number of ways 1,2,...,n can be divided into two sets of equal sums.
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
const int maxn=5e2;
ll dp[maxn*(maxn+1)/2+1];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int s = n * (n + 1) / 2;
    if(s & 1)
    {
        cout << 0;
        exit(0);
    }
    s /= 2;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i * (i + 1) / 2; j >= i; --j)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout <<dp[s]*((mod+1)/2)%mod;
    return 0;
}
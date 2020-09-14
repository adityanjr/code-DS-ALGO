// minimum path length of exactly k edges
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
const ll inf = 1e18+100;
#define mat vector<vector<ll>>
inline ll add(ll a, ll b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
inline ll mul(ll a, ll b)
{
    return  (a % mod * (b % mod)) % mod;
}
mat multiply( mat a, mat b)
{
    assert(a[0].size() == b.size());
    mat c(a.size(), vector<ll>(b[0].size(), inf));
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j)
            for(int k = 0; k < b.size(); ++k)
                c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
    return c;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    mat a(n, vector<ll>(n, inf));
    mat b(n, vector<ll>(n, inf));
    for(int i = 0; i < n; i++)
        b[i][i] = 0;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        ll v;
        cin >> x >> y >> v, --x, --y;
        a[x][y] = min(a[x][y], v);
    }
    while(k)
    {
        if(k & 1)
            b = multiply(b, a);
        a = multiply(a, a);
        k /= 2;
    }
    if(b[0][n - 1] >= inf)
        cout << "-1";
    else
        cout << b[0][n - 1];
    return 0;
}
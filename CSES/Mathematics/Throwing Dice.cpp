// number of ways to get sum n from any number of dices sums.
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
    mat c(a.size(), vector<ll>(b[0].size(), 0));
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b[0].size(); ++j)
            for(int k = 0; k < b.size(); ++k)
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    return c;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    mat a = {{0, 0, 0, 0, 0, 1}};
    mat b =
    {
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1}
    };
    ll n;
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        exit(0);
    }
    while(n)
    {
 
        if(n & 1)
            a = multiply(a, b);
        b = multiply(b, b);
        n >>= 1;
    }
    cout<<a[0][5];
    return 0;
}
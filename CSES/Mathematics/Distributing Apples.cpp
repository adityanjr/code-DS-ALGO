// number of ways to distribute to n children m apples
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
const int mxn = 2e6 + 2;
ll fact[mxn];
inline ll add(ll a, ll b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
inline ll sub(ll a, ll b)
{
    a -= b;
    if (a < 0) a += mod;
    return a;
}
inline ll mul(ll a, ll b)
{
    return  (a * b % mod);
}
ll power(ll x, ll y)
{
    x %= mod;
    y %= (mod - 1);
    ll res = 1;
    for(; y; y >>= 1, x = mul(x, x))
        if(y & 1)
            res = mul(res, x);
    return res;
}
ll inv(ll x)
{
    return power(x, mod - 2);
}
ll ncr(ll n, ll r)
{
    return mul(mul(fact[n], inv(fact[r])), inv(fact[n - r]));
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    forn(i, 1, mxn - 1)
    fact[i] = mul(fact[i - 1], i);
    int a, b;
    cin >> a >> b;
    cout << ncr(a+b-1,b);
    return 0;
}
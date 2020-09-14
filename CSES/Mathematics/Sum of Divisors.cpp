// Find the sum of divisors of all numbers from 1 to n
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
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0; 
    for(ll i = 1; i <= n; ++i)
    {
        ll r=n/(n/i);
        ans=(ans+(n/i)*(((r%mod*((r+1)%mod))%mod*(((mod+1)/2)%mod))%mod-((i%mod*((i-1)%mod))%mod*(((mod+1)/2)%mod))%mod))%mod;
        i=r;
    }
    cout << (ans%mod+mod)%mod;
    return 0;
}
// nth fibonacci number exponentiation
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
void multiply( vector<vector<ll>> &a,  vector<vector<ll>>b)
{
    vector<vector<ll>>c(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        {
            c[i][j] = 0;
            for(int k = 0; k < 2; ++k)
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
        }
    a = c;
}
void raise_power(vector<vector<ll>> &a, ll y)
{
    vector<vector<ll>>b = a;
    if(y == 1)
        return;
    raise_power(a, y >> 1);
    multiply(a, a);
    if(y & 1)
        multiply(a, b);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<ll>>vec = {{0, 1}, {1, 1}};
    ll n;
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        exit(0);
    }
    raise_power(vec, n);
    cout << vec[1][0];
    return 0;
}
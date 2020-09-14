// Find the kth ancestor for the given node.
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
const int maxn = 2e5 + 5;
const int lg = 18;
int par[maxn][lg];
int n;
void binary_lift()
{
    for(int h = 1; h < lg; ++h)
        for(int i = 1; i <= n; i++)
            par[i][h] = par[par[i][h - 1]][h - 1];
}
int query(int u, int k)
{
    for(int i = lg - 1; i >= 0; --i)
        if(k & (1 << i))
            u = par[u][i];
    if(u == 0)
        return -1;
    return u;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        int u;
        cin >> u;
        par[i][0] = u;
    }
    binary_lift();
    for(int i = 1; i <= q; i++)
    {
        int u, k;
        cin >> u >> k;
        cout << query(u, k) << '\n';
    }
    return 0;
}

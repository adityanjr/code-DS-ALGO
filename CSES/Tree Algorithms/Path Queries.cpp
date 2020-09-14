// Update the nodes and ask sum of path from root to given node
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
const int maxn = 4e5 + 5;
vector<int>g[maxn];
int ds[maxn], de[maxn], dt;
ll ft[maxn];
int n;
void dfs(int u, int p)
{
    ds[u] = ++dt;
    for(auto v : g[u])
        if(v != p)
        {
            dfs(v, u);
        }
    de[u] = ++dt;
}
void upd(int x, const ll &v)
{
    for(; x <= de[1]; x += x & -x)
        ft[x] += v;
}
ll get(int x)
{
    ll res = 0;
    for(; x; x -= x & -x)
        res += ft[x];
    return res;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
    }
    for(int i = 2; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1, 0);
    rep(i, n)
    {
        upd(ds[i + 1], a[i]);
        upd(de[i + 1], -a[i]);
    }
    for(int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int u;
            ll v;
            cin >> u >> v;
            upd(ds[u], v - a[u - 1]);
            upd(de[u], a[u - 1] - v);
            a[u - 1] = v;
        }
        else
        {
            int u;
            cin >> u;
            cout << get(ds[u]) << '\n';
        }
    }
    return 0;
}
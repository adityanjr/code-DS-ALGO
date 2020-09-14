// find sum of all pair distances of nodes in a tree.
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
const int maxn = 2e5;
vector<int>g[maxn];
ll d[maxn];
ll sz[maxn], ans[maxn];
int n;
void dfs(int u, int p)
{
    d[u] = d[p] + 1;
    sz[u] = 1;
    for(auto v : g[u])
        if(v != p)
        {
            dfs(v, u);
            sz[u] += sz[v];
            ans[0] += d[v];
        }
}
void dfs2(int u, int p)
{
    if(u != p)
    {
        ans[u] = ans[p] - sz[u] + (n - sz[u]);
    }
    for(auto v : g[u])
    {
        if(v != p)
        {
            dfs2(v, u);
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[0] = -1;
    dfs(0, 0);
    dfs2(0, 0);
    rep(i, n)
    cout << ans[i] << ' ';
    return 0;
}
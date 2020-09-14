// Distance between two nodes.
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
vector<int>g[maxn];
int par[maxn][lg];
int lv[maxn];
int n;
void dfs(int u, int p)
{
    lv[u] = lv[p] + 1;
    par[u][0] = p;
    for(auto v : g[u])
        if(v != p)
        {
            dfs(v, u);
        }
}
void binary_lift()
{
    for(int h = 1; h < lg; ++h)
        for(int i = 1; i <= n; i++)
            par[i][h] = par[par[i][h - 1]][h - 1];
}
int lca(int u, int v)
{
    if(lv[u] > lv[v])
        swap(u, v);
    int diff = lv[v] - lv[u];
    for(int h = lg - 1; ~h; --h)
        if((diff >> h) & 1)
            v = par[v][h];
    if(u == v)
        return u;
    for(int h = lg - 1; ~h; --h)
        if(par[u][h] && par[u][h] != par[v][h])
            u = par[u][h], v = par[v][h];
    return par[u][0];
}
int dist(int a, int b)
{
    int x = lca(a, b);
    return lv[a] + lv[b] - 2 * lv[x];
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1, 0);
    binary_lift();
    for(int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << dist(u, v) << '\n';
    }
    return 0;
}
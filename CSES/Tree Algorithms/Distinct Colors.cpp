// Find the number of distinct colors in a subtree of each node.
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
int a[maxn];
vector<int>g[maxn];
int ans[maxn];
vector<int> *vec[maxn];
int n;
int sz[maxn];
unordered_map<int, bool>vis;
void getsz(int u, int p)
{
    sz[u] = 1;
    for(auto v : g[u])
        if(v != p)
        {
            getsz(v, u);
            sz[u] += sz[v];
        }
}
void dfs(int u, int p, bool keep)
{
    int mx = -1, big = -1;
    for(auto v : g[u])
        if(v != p)
            if(sz[v] > mx)
                mx = sz[v], big = v;
    for(auto v : g[u])
        if(v != p && v != big)
            dfs(v, u, 0);
    if(big != -1)
    {
        dfs(big, u, 1);
        vec[u] = vec[big];
        ans[u] = ans[big];
    }
    else
        vec[u] = new vector<int>(), ans[u] = 0;
    vec[u]->push_back(u);
    if(!vis[a[u - 1]])
    {
        vis[a[u - 1]] = 1;
        ans[u]++;
    }
    for(auto v : g[u])
        if(v != p && v != big)
            for(auto x : *vec[v])
            {
                if(!vis[a[x - 1]])
                {
                    ans[u]++;
                    vis[a[x - 1]] = 1;
                }
                vec[u]->push_back(x);
            }
    if(!keep)
    {
        for(auto x : *vec[u])
            vis[a[x - 1]] = 0;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<int, int>>v;
    rep(i, n)
    {
        cin >> a[i];
        v.emplace_back(a[i], i);
    }
    sort(all(v));
    int c = 0, prev = -1;
    trav(x, v)
    {
        if(x.ff != prev)
            prev = x.ff, a[x.ss] = ++c;
        else
            a[x.ss] = c;
    }
    vis.reserve(c);
    for(int i = 2; i <= n; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    getsz(1, 0);
    dfs(1, 0, 0);
    forn(i, 1, n)
    cout << ans[i] << ' ';
    return 0;
}
// Longest Path or find if positive cycle exist(Bellman Ford)
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
const ll inf = 1e18;
const int maxn = 2e3 + 505;
bool vis1[maxn];
bool vis2[maxn];
vector<int>gr[maxn];
vector<int>g[maxn];
void dfs1(int u)
{
    vis1[u] = 1;
    for(auto v : gr[u])
    {
        if(!vis1[v])
            dfs1(v);
    }
}
void dfs2(int u)
{
    vis2[u] = 1;
    for(auto v : g[u])
    {
        if(!vis2[v])
            dfs2(v);
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll d[n];
    rep(i, n)
    d[i] = -inf;
    vector<tuple<int, int, ll>>edges;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y, --x, --y;
        ll w;
        cin >> w;
        edges.push_back({x, y, w});
        gr[y].push_back(x);
        g[x].push_back(y);
    }
    dfs1(n - 1);
    dfs2(0);
    d[0] = 0;
    bool f = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(auto e : edges)
        {
            int u, v;
            ll w;
            tie(u, v, w) = e;
            if(d[v] < d[u] + w)
            {
                if(i == n && vis1[v] && vis2[v])
                {
                    f = 1;
                }
                d[v] = d[u] + w;
            }
        }
    }
    if(f)
    {
        cout << "-1";
        exit(0);
    }
    cout << d[n - 1];
    return 0;
}
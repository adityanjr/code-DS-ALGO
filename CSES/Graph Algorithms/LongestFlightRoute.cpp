// Longest Path in a DAG using Toplogical Sort.
// Start from the sink and traverse up the DAG.
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
const int maxn = 1e5;
vector<int>g[maxn];
vector<int>gr[maxn];
bool vis[maxn];
vector<int>order;
const int inf = 1e9;
void dfs(int u)
{
    vis[u] = 1;
    trav(v, g[u])
    if(!vis[v])
        dfs(v);
    order.push_back(u);
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        g[v].push_back(u);
    }
    rep(i, n)
    if(!vis[i])
        dfs(i);
    int d[n];
    rep(i, n)
    d[i] = -inf;
    d[0] = 0;
    int p[n];
    iota(p, p + n, 0);
    trav(x, order)
    {
        trav(y, g[x])
        {
            // Original graph has y->x edge
            if(d[x] < d[y] + 1 && d[y] != -inf)
            {
                d[x] = d[y] + 1;
                p[x] = y;
            }
        }
    }
    if(d[n - 1] == -inf)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int>path;
    for(int x = n - 1; x != p[x]; x = p[x])
    {
        path.push_back(x);
    }
    path.push_back(0);
    reverse(all(path));
    cout << path.size() << '\n';
    trav(x, path)
    cout << x + 1 << ' ';
    return 0;
}
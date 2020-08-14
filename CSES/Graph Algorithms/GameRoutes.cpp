// Number of ways to travel from source to destination in a DAG.
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
const int mod = 1e9 + 7;
vector<int>g[maxn];
vector<int>gr[maxn];
bool vis[maxn];
vector<int>order;
const int inf = 1e9;
inline ll add(ll a, ll b)
{
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
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
    int ways[n];
    rep(i, n)
    ways[i] = 0;
    ways[0] = 1;
    trav(x, order)
    {
        trav(y, g[x])
        {
            ways[x] = add(ways[x], ways[y]);
        }
    }
    cout << ways[n - 1];
    return 0;
}
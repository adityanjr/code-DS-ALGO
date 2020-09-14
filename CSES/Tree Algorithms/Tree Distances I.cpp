// Find eccentricity for each node in a tree.
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
int ln = 0;
int d1[maxn],d2[maxn];
void dfs(int u, int p,int d[maxn])
{
    d[u] = d[p] + 1;
    for(auto v : g[u])
        if(v != p)
            dfs(v, u,d);
    if(d[ln] < d[u])
    {
        ln = u;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0,d1);
    d1[ln] = -1;
    dfs(ln, ln,d1);
    d2[ln] = -1;
    dfs(ln, ln,d2);
    rep(i,n)
    cout<<max(d1[i],d2[i])<<' ';
    return 0;
}
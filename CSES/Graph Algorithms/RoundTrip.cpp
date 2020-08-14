// Print any cycle in a graph
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
const int maxn = 1e5 + 5;
vector<int>g[maxn];
bool vis[maxn];
bool act[maxn];
int p[maxn];
int node1 = -1, node2 = -1;
void dfs(int u)
{
    vis[u] = 1;
    act[u] = 1;
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            p[v] = u;
            dfs(v);
        }
        else if(act[v] && v != p[u])
        {
            node1 = u;
            node2 = v;
        }
    }
    act[u] = 0;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    p[0]=-1;
    bool flag = false;
    rep(i, n)
    {
        if(!vis[i])
            dfs(i);
    }
    if(node1==node2)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    vector<int>v;
    for(int x=node1;x!=node2;x=p[x])
    {
        v.push_back(x+1);
    }
    v.push_back(node2+1);
    v.push_back(node1+1);
    cout<<v.size()<<'\n';
    trav(x,v)
    {
        cout<<x<<' ';
    }
    return 0;
}
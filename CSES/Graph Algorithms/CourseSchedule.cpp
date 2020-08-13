// Topological sort the courses and print the order.
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
bool vis[maxn], act[maxn];
vector<int>order;
bool dfs(int u)
{
    act[u] = 1;
    vis[u] = 1;
    bool flag = true;
    trav(v, g[u])
    {
        if(!vis[v])
        {
            flag &= dfs(v);
        }
        else if(act[v])
        {
            flag = false;
            break;
        }
    }
    order.push_back(u);
    act[u] = 0;
    return flag;
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
    bool f = 1;
    for(int i = 0; i < n && f; i++)
    {
        if(!vis[i])
        {
            f &= dfs(i);
        }
    }
    if(!f)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    trav(x, order)
    cout << x + 1 << ' ';
    return 0;
}
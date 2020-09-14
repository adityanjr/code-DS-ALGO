// Find Tree Diameter using single DFS.
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
int d[maxn];
int ans;
void dfs(int u, int p)
{
    for(auto v : g[u])
        if(v != p)
        {
            dfs(v, u);
            ans = max(ans, d[u] + d[v] + 1);
            d[u] = max(d[u], d[v] + 1);
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
    dfs(0, -1);
    cout << ans;
    return 0;
}
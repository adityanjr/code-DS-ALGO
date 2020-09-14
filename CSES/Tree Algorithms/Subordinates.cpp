// Subtree size for each node.
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
int sz[maxn];
void dfs(int u, int p)
{
    sz[u] = 1;
    for(auto v : g[u])
        if(v != p)
        {
            dfs(v, u);
            sz[u] += sz[v];
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
        int u;
        cin >> u, --u;
        g[u].push_back(i);
    }
    for(int i = 0; i < n; i++)
    {
        if(sz[i] == 0)
            dfs(i, i);
    }
    for(int i = 0; i < n; i++)
        cout << sz[i] - 1 << ' ';
    return 0;
}
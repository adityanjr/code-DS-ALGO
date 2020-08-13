// Find the shortest distance if we can discount on one edge
// Double DFS or A* algorithm from source and destination.
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
vector<pair<int, int>>g[maxn];
vector<pair<int, int>>gr[maxn];
ll d1[maxn], d2[maxn];
void solve(int ss, vector<pair<int, int>>g[maxn], ll d[maxn])
{
    memset(d, 0x3f, sizeof d1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>s;
    d[ss]=0;
    s.push({0, ss});
    while(!s.empty())
    {
        auto cur = s.top();
        s.pop();
        ll w = cur.ff;
        int u = cur.ss;
        if(d[u] < w) continue;
        for(auto v : g[u])
        {
            if(d[v.ff] > v.ss + w)
            {
                d[v.ff] = v.ss + w;
                s.push({d[v.ff], v.ff});
            }
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].emplace_back(v - 1, w);
        gr[v - 1].emplace_back(u - 1, w);
    }
    solve(0, g, d1);
    solve(n - 1, gr, d2);
    ll cost=1e18;
    rep(i,n)
    {
        for(auto v:g[i])
        {
            cost=min(cost,d1[i]+d2[v.ff]+v.ss/2);
        }
    }
    cout<<cost;
    return 0;
}
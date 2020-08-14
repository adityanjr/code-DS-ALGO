// Shortest Weighted Path (Dijkstra)
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].emplace_back(v - 1, w);
    }
    ll d[n];
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>s;
    s.push({0, 0});
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
    rep(i, n)
    cout << d[i] << ' ';
    return 0;
}

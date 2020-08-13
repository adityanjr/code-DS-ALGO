// Find the negative cycle and print it.
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>>g(m);
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        g[i] = {u, v, w};
    }
    int x = -1;
    ll d[n];
    int p[n];
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    p[0] = 0;
    rep(i, n)
    {
        x = -1;
        for(auto e : g)
        {
            int u = e[0], v = e[1];
            ll w = e[2];
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                x = v;
                p[v] = u;
            }
        }
    }
    if(x == -1)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    rep(i, n)
    x = p[x];
    vector<int>cycle;
    for(int u = x;; u = p[u])
    {
        if(u == x && cycle.size())
        {
            break;
        }
        cycle.push_back(u);
    }
    cycle.push_back(x);
    reverse(all(cycle));
    trav(c,cycle)
    {
        cout<<c+1<<' ';
    }
    return 0;
}
// Print k shortest paths.
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<array<ll, 2>>g[n];
    vector<ll>d[n];
    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        g[u].push_back({v, w});
    }
    priority_queue < array<ll, 2>, vector < array<ll, 2>>, greater<array<ll, 2>>>q;
    q.push({0, 0});
    while(!q.empty())
    {
        array<ll, 2>u = q.top();
        q.pop();
        if(d[u[1]].size() >= k)
            continue;
        d[u[1]].push_back(u[0]);
        for(auto v:g[u[1]])
        {
            q.push({u[0]+v[1],v[0]});
        }
    }
    rep(i,k)
    cout<<d[n-1][i]<<' ';
    return 0;
}

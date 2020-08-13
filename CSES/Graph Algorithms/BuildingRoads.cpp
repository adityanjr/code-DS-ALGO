// Minimum edges to connect the graph
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; ++i)
struct DSU
{
    vector<ll>par, sz;
    int comp;
    DSU(ll n)
    {
        par.resize(n);
        comp = n;
        sz = vector<ll>(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x)
    {
        if(x != par[x])
            return par[x] = find(par[x]);
        return x;
    }
    bool merge(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if(a == b)
            return false;
        if(sz[a] < sz[b])
            swap(a, b);
        comp--;
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y, --x, --y;
        dsu.merge(x, y);
    }
    cout << dsu.comp - 1 << '\n';
    if(dsu.comp > 1)
    {
        vector<int>v;
        rep(i, n)
        {
            if(dsu.find(i) == i)
            {
                v.emplace_back(i);
            }
        }
        rep(i, v.size() - 1)
        {
            cout << v[i]+1 << ' ' << v[i + 1]+1 << '\n';
        }
    }
    return 0;
}
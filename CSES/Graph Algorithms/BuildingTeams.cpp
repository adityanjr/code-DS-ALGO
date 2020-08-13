// Bipartite Check
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
template<typename T>
class graph
{
public:
    struct edge
    {
        int from;
        int to;
        T cost;
    };
    vector<vector<edge>>adj;
    vector<edge>edges;
    int n;
    graph(int _n) : n(_n)
    {
        adj.resize(n);
    }
    virtual void add(int from, int to, T cost) = 0;
};
template<typename T>
class undigraph : public graph<T>
{
public:
    using graph<T>::edges;
    using graph<T>::n;
    using graph<T>::adj;
    vector<T>color;
    undigraph(int _n) : graph<T>(_n)
    {
        color.resize(n, -1);
    }
    void add(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n && 0 <= to && to < n);
        adj[from].push_back({from, to, cost});
        adj[to].push_back({to, from, cost});
        edges.push_back({from, to, cost});
    }
    bool dfs(int u)
    {
        bool flag=true;
        for(auto v : adj[u])
        {
            if(color[v.to] == -1)
            {
                color[v.to] = color[u] ^ 1;
                flag &= dfs(v.to);
            }
            else if(color[v.to] == color[u])
            {
                return false;
            }
        }
        return flag;
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    undigraph<int>g(n);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y, --x, --y;
        g.add(x, y);
    }
    bool flag = true;
    rep(i, n)
    {
        if(g.color[i] == -1)
        {
            g.color[i] = 0;
            flag &= g.dfs(i);
        }
    }
    if(!flag)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    rep(i, n)
    {
        cout << g.color[i] + 1 << ' ';
    }
    return 0;
}
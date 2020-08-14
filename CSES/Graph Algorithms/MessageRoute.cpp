// Shortest Path BFS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; ++i)
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>g[n];
    rep(i, m)
    {
        int x, y;
        cin >> x >> y, --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int>q;
    int p[n];
    bool vis[n];
    memset(vis, 0, sizeof vis);
    q.push(0);
    vis[0] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(!vis[v])
            {
                p[v] = u;
                q.push(v);
                vis[v] = 1;
            }
        }
        if(vis[n - 1])
            break;
    }
    if(!vis[n - 1])
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    vector<int>path;
    for(int x = n - 1; x; x = p[x])
        path.push_back(x);
    cout << path.size() + 1 << '\n';
    cout << "1 ";
    for(int i = path.size() - 1; ~i; --i)
        cout << path[i] + 1 << ' ';
    return 0;
}
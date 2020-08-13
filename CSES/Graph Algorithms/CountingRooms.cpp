// Find the number of connected components in a grid of path and obstacles.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; ++i)
const int maxn = 1e3;
int n, m;
bool vis[maxn][maxn];
string a[maxn];
inline int get(int i, int j)
{
    return i * m + j;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j)
{
    vis[i][j] = 1;
    rep(k, 4)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && a[ni][nj] == '.')
            dfs(ni, nj);
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, n)
    cin >> a[i];
    int ans = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            if(!vis[i][j] && a[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
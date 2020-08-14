// Print path from source to destination in a grid.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; ++i)
const int maxn = 1e3 + 5;
int n, m;
bool vis[maxn][maxn];
string a[maxn];
array<int, 2>parent[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i, n)
    cin >> a[i];
    int si, sj;
    int r, c;
    rep(i, n)
    {
        rep(j, m)
        {
            if(a[i][j] == 'A')
            {
                si = i, sj = j;
            }
            if(a[i][j] == 'B')
                r = i, c = j;
        }
    }
    queue<array<int, 2>>q;
    q.push({si, sj});
    bool found = 0;
    parent[si][sj] = {si, sj};
    while(!q.empty())
    {
        if(found)
            break;
        auto it = q.front();
        q.pop();
        vis[it[0]][it[1]] = 1;
        rep(k, 4)
        {
            if(found)
                break;
            int ni = it[0] + dx[k];
            int nj = it[1] + dy[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && a[ni][nj] != '#')
            {
                parent[ni][nj] = {it[0], it[1]};
                if(ni == r && nj == c)
                {
                    found = 1;
                    break;
                }
                q.push({ni, nj});
                a[ni][nj]='#';
            }
        }
    }
    if(found)
    {
        string ans = "";
        while(1)
        {
            if(parent[r][c][0] == r && parent[r][c][1] == c)
                break;
            if(r == parent[r][c][0])
            {
                if(parent[r][c][1] == c - 1)
                    ans += "R";
                else if(parent[r][c][1] == c + 1)
                    ans += "L";
            }
            else
            {
                if(parent[r][c][0] == r - 1)
                    ans += "D";
                else if(parent[r][c][0] == r + 1)
                    ans += "U";
            }
            int x = parent[r][c][0];
            int y = parent[r][c][1];
            r = x;
            c = y;
        }
        cout << "YES\n";
        cout << ans.size() << '\n';
        for(int i = ans.size() - 1; ~i; i--)
            cout << ans[i];
    }
    else
        cout << "NO\n";
    return 0;
}
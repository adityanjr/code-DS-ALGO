// Find number of ones in a bool 2d array in a given sub-matrix with updates.
// 2D Fenwick Tree
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1e3 + 1;
string a[maxn];
int n;
int ft[maxn][maxn];
void modify(int x, int y, int v)
{
    for(int i = x + 1; i <= n; i += i & -i)
    {
        for(int j = y + 1; j <= n; j += j & -j)
            ft[i][j] += v;
    }
}
int get(int x, int y)
{
    int res = 0;
    for(int i = x; i ; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            res += ft[i][j];
    return res;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == '*')
                modify(i, j, 1);
        }
    }
    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(a[u][v] == '*')
            {
                a[u][v] = '.';
                modify(u, v, -1);
            }
            else
            {
                a[u][v] = '*';
                modify(u, v, 1);
            }
        }
        else
        {
            int y1, x1, y2, x2;
            cin >> x1 >> y1 >> x2 >> y2, y1--, x1--;
            cout << get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1) << '\n';
        }
    }
}
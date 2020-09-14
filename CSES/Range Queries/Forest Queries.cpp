// Number of ones in a bool 2d array in a given sub-matrix
// inclusion exclusion principle
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1e3 + 1;
string a[maxn];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int pre[n + 1][n + 1];
    memset(pre, 0, sizeof pre);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == '*')
                ++pre[i + 1][j + 1];
        }
        for(int j = 0; j < n; j++)
        {
            pre[i + 1][j + 1] += pre[i + 1][j];
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            pre[i + 1][j + 1] += pre[i][j + 1];
    for(int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2, y1--, x1--;
        cout << pre[x2][y2] - pre[x1][y2] - pre[x2][y1] + pre[x1][y1] << '\n';
    }
}

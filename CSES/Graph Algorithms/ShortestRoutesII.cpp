// Shortest weighted All Pair Path(Floyd Warshall)
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
const ll inf = 1e18;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    ll d[n][n];
    rep(i, n) rep(j, n) d[i][j] = inf;
    rep(i, n) d[i][i] = 0;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y, x--, y--;
        ll v;
        cin >> v;
        d[x][y] = min(d[x][y], v);
        d[y][x] = min(d[y][x], v);
    }
    rep(k, n)   rep(i, n)   rep(j, n)
    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    rep(i, q)
    {
        int x, y;
        cin >> x >> y, --x, --y;
        if(d[x][y] != inf)
            cout << d[x][y] << '\n';
        else
            cout << "-1\n";
    }
    return 0;
}
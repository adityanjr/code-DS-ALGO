//Number of ways two queens don't attack each other.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (int i = 0; i < n; ++i)
#define forn(i,a,b) for (int i =a; i <b; ++i)
#define revforn(i,a,b) for (int i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
const int n = 8;
string s[n];
ll ans;
void solve(int r, const function<bool(int, int)> &check)
{
    if(r == n)
    {
        ans++;
        return;
    }
    for(int j = 0; j < n; j++)
    {
        if(s[r][j] != '*' && check(r, j))
        {
            s[r][j] = 'Q';
            solve(r + 1, check);
            s[r][j] = '.';
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rep(i, n)
    cin >> s[i];
    function<bool(int, int)>check = [&](int row, int col)->bool
    {
        for(int i = 0; i < n; i++)
            if(s[i][col] == 'Q')
                return false;
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(s[i][j] == 'Q')
                return false;
        for(int i = row, j = col; i >= 0 && j < n; i--, j++)
            if(s[i][j] == 'Q')
                return false;
        return true;
    };
    solve(0,check);
    cout << ans;
    return 0;
}

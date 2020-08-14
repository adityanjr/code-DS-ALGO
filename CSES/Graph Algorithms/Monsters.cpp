// BFS from monsters and player to all boundaries. 
// If player reach any boundary first then answer is valid.
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
const int inf = 1e6 + 5;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s[n];
    rep(i, n)
    cin >> s[i];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    array<int, 2>p1[n][m];
    array<int, 2>p2[n][m];
    int si, sj;
    vector<pair<int, int>>monsters;
    auto check = [&](int i, int j)->bool
    {
        return (i >= 0 && j >= 0 && i < n && j < m && s[i][j] == '.');
    };
    rep(i, n)
    {
        rep(j, m)
        {
            if(s[i][j] == 'A')
                si = i, sj = j, s[i][j] = '.';
            else if(s[i][j] == 'M')
                monsters.emplace_back(i, j), s[i][j] = '.';
            p1[i][j] = {-1, -1};
        }
    }
    vector<vector<int>>d1(n, vector<int>(m, inf));
    vector<vector<bool>>v1(n, vector<bool>(m, 0));
    vector<vector<int>>d2(n, vector<int>(m, inf));
    vector<vector<bool>>v2(n, vector<bool>(m, 0));
    queue<pair<int, int>>q;
    q.push({si, sj});
    v1[si][sj] = true;
    d1[si][sj] = 0;
    p1[si][sj] = {si, sj};
    while(!q.empty())
    {
        pair<int, int>u = q.front();
        q.pop();
        rep(k, 4)
        {
            int ni = u.first + dx[k];
            int nj = u.second + dy[k];
            if(check(ni, nj) && !v1[ni][nj])
            {
                d1[ni][nj] = d1[u.ff][u.ss] + 1;
                p1[ni][nj] = {u.ff, u.ss};
                q.push({ni, nj});
                v1[ni][nj] = 1;
            }
        }
    }
    assert(q.empty());
    trav(x, monsters)
    {
        q.push({x.ff, x.ss});
        v2[x.ff][x.ss] = true;
        d2[x.ff][x.ss] = 0;
        p2[x.ff][x.ss] = {x.ff, x.ss};
    }
    while(!q.empty())
    {
        pair<int, int>u = q.front();
        q.pop();
        rep(k, 4)
        {
            int ni = u.first + dx[k];
            int nj = u.second + dy[k];
            if(check(ni, nj) && !v2[ni][nj])
            {
                d2[ni][nj] = d2[u.ff][u.ss] + 1;
                p2[ni][nj] = {u.ff, u.ss};
                q.push({ni, nj});
                v2[ni][nj] = 1;
            }
        }
    }
    int li = -1, lj = -1;
    rep(j, m)
    {
        if(d1[0][j] < d2[0][j])
            li = 0, lj = j;
        if(d1[n - 1][j] < d2[n - 1][j])
            li = n - 1, lj = j;
    }
    rep(i, n)
    {
        if(d1[i][0] < d2[i][0])
            li = i, lj = 0;
        if(d1[i][m - 1] < d2[i][m - 1])
            li = i, lj = m - 1;
    }
    if(li == -1)
    {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    string ans = "";
    while(1)
    {
        if(p1[li][lj][0] == li && p1[li][lj][1] == lj)
            break;
        array<int, 2>x = p1[li][lj];
        if(x[0]==li)
        {
            if(x[1]==lj-1)
            {
                ans+="R";
            }
            else
            {
                ans+="L";
            }
        }
        else
        {
            if(x[0]==li+1)
            {
                ans+="U";
            }
            else
            {
                ans+="D";
            }
        }
        li = x[0];
        lj = x[1];
    }
    reverse(all(ans));
    cout<<ans.size()<<'\n';
    cout<<ans;
    return 0;
}
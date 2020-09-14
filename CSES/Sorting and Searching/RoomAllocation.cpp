// Find the minimum number of non intersecting disjoint segments group
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<int, 3>a[n];
    rep(i, n)
    {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    // Sort by end time
    sort(a, a + n);
    set<array<int, 2>>s;
    int ans[n];
    rep(i, n)
    {
        auto it = s.lower_bound({a[i][1]});
        // Check if cur seg can be placed without intersecting
        if(it != s.begin())
        {
            --it;
            ans[a[i][2]] = (*it)[1];
            s.erase(it);
        }
        else
            ans[a[i][2]] = s.size();
        s.insert({a[i][0], ans[a[i][2]]});
    }
    cout << s.size() << '\n';
    rep(i, n)
    cout << ans[i] + 1 << ' ';
    return 0;
}
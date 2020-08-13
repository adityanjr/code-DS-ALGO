// LIS length O(nlogn)
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
const int mod = 1e9 + 7;
const int maxn = 5e2;
ll dp[maxn * (maxn + 1) / 2 + 1];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    rep(i, n)
    cin >> a[i];
    set<int>s;
    rep(i, n)
    {
        auto it = s.lower_bound(a[i]);
        if(it == s.end())
            s.insert(a[i]);
        else
        {
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size();
    return 0;
}
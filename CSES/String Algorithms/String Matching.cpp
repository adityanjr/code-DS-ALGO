// number of matches of a pattern in a text
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define forn(i,a,b) for (ll i =a; i <=b; ++i)
#define revforn(i,a,b) for (ll i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t, p;
    cin >> t >> p;
    int x = p.size();
    p = p + "#" + t;
    int n = p.size();
    int ans = 0;
    vector<int>lps(n, 0);
    for(int i = 1; i < n; ++i)
    {
        int j = lps[i - 1];
        while(j > 0 && p[j] != p[i]) j = lps[j - 1];
        if(p[i] == p[j]) j++;
        lps[i] = j;
        ans+=(lps[i]==x);
    }
    cout << ans;
    return 0;
}
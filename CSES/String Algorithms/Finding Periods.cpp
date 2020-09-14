// Find the number of periods of the given string.
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
    string s;
    cin >> s;
    int n = s.size();
    set<int>ans;
    vector<int>z(n);
    z[0] = 0;
    for(int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if(i <= r)
        {
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] + 1 > r)
            l = i, r = i + z[i] - 1;
    }
    forn(i, 1, n - 1)
    if(z[i] + i == n)
        cout << i << ' ';
    // [0,i-1] strings are there.
    cout << n << '\n'; //self string
    return 0;
}
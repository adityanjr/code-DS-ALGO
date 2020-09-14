// Given n length stick and m points that cuts the stick, find length of maximum segment after each cut.
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
    int x, n;
    cin >> x >> n;
    int a[n];
    set<int>p;
    p.insert(0);
    p.insert(x);
    map<int, int>mp;
    mp[x] = 1;
    rep(i, n)
    {
        cin >> a[i];
        auto it = p.lower_bound(a[i]);
        int r = *it;
        it--;
        int l = *it;
        mp[r - l]--;
        if(!mp[r - l])
            mp.erase(r - l);
        p.insert(a[i]);
        mp[r - a[i]]++;
        mp[a[i] - l]++;
        cout << (--mp.end())->first << ' ';
    }
    return 0;
}

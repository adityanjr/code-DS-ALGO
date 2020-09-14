// Given time intervals of n movies, find how many movie can be completely covered by one person.
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
    vector<pair<int, int>>a;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    int ans = 0;
    int prev=0;
    sort(all(a), [&](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    });
    for(auto it : a)
    {
        if(prev<=it.first)
        {
            ans++;
            prev=it.second;
        }
    }
    cout<<ans;
    return 0;
}

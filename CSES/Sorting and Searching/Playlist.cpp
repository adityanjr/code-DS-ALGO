// Find maximum subarray size of distinct elements
// Two pointers
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
    int a[n];
    rep(i, n)
    cin >> a[i];
    int ans = 0;
    map<int, int>mp;
    for(int i = 0, j = 0; i < n; i++)
    {
        while(j < n && mp[a[j]] < 1)
        {
            mp[a[j]]++;
            j++;
        }
        ans = max(ans, j - i);
        mp[a[i]]--;
    }
    cout << ans;
    return 0;
}
// Find the indices of all substrings that is prefix and suffix and not the string itself.
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
    vector<int>z(n, 0);
    for(int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if(i > r)
        {
            l = r = i;
            while(r < n && s[r - l] == s[r]) r++;
            z[i] = r - l;
            --r;
        }
        else
        {
            if(z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else
            {
                l = i;
                while(r < n && s[r - l] == s[r]) r++;
                z[i] = r - l;
                --r;
            }
        }
        if(z[i]==n-i)
        	ans.insert(z[i]);
    }
    for(int x:ans)
    	cout<<x<<' ';
    return 0;
}
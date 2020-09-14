// Find three distinct indices that add upto given number O(n^2logn)
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<pair<ll, int>>a(n);
    rep(i, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    auto binary_search = [&](int lo, int hi, int target)->int
    {
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;
            if(a[mid].first < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if(hi==lo && a[hi].first == target)
            return hi;
        return -1;
    };
    set<int>ans;
    bool flag = true;
    for(int i = 0; i < n && flag; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i].first + a[j].first < x)
            {
                int idx = binary_search(j + 1, n - 1, x - a[i].first - a[j].first);
                if(idx != -1)
                {
                    ans.insert(a[i].second + 1);
                    ans.insert(a[j].second + 1);
                    ans.insert(a[idx].second + 1);
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag == false)
    {
        for(int x : ans)
            cout << x << ' ';
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}

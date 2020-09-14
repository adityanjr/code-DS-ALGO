// Find four distinct indices that add upto given number
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
struct event
{
    ll v;
    int l, r;
    event(ll _v, int _l, int _r): v(_v), l(_l), r(_r) {}
    bool operator<(const event &a)
    {
        return v < a.v;
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    ll a[n];
    vector<event>vec;
    rep(i, n)
    cin >> a[i];
    rep(i, n)
    {
        forn(j, i + 1, n - 1)
        {
            vec.emplace_back(a[i] + a[j], i, j);
        }
    }
    sort(all(vec));
    auto binary_search = [&](int lo, int hi, int target)->event
    {
        while(lo < hi)
        {
            int mid = (lo + hi) >> 1;
            if(vec[mid].v < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if(vec[hi].v == target)
            return vec[hi];
        return event(-1ll, -1, -1);
    };
    set<int>s;
    rep(i, vec.size())
    {
        if(vec[i].v + 1 >= x)
            break;
        event ev = binary_search(i + 1, vec.size() - 1, x - vec[i].v);
        if(ev.l != -1)
        {
            s.insert(vec[i].l);
            s.insert(vec[i].r);
            s.insert(ev.l);
            s.insert(ev.r);
            if(s.size() == 4)
                break;
            else
                s.clear();
        }
    }
    if(s.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int x : s)
        cout << x + 1 << ' ';
    return 0;
}

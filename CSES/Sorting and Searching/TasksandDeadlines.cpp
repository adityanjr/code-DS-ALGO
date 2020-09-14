// Shortest Job First (We know the burst time and deadline in advance for each job)
// SJF has minimum average waiting time
// It is a greedy algorithm
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
    array<int,2>p[n];
    rep(i, n)
    {
        cin>>p[i][0]>>p[i][1];
    }
    sort(p,p+n);
    ll ans=0;
    ll t=0;
    rep(i,n)
    {
        t+=p[i][0];
        ans+=(p[i][1]-t);
    }
    cout<<ans;
    return 0;
}
// Given n segments find the point covered by most segments
// Given arrival and departure time find the time of maximum crowd
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
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.emplace_back(x,i);
        a.emplace_back(y,i);
    }
    sort(all(a));
    int ans=0;
    bool vis[n];
    memset(vis,0,sizeof vis);
    int cnt=0;
    for(auto it:a)
    {
        int i=it.second;
        if(vis[i])
        {
            cnt--;
        }
        else
        {
            cnt++;
            vis[i]=1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}

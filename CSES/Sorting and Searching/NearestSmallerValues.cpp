// Find PSE(Previous Smaller Element)
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
    int n;
    cin >> n;
    ll a[n];
    rep(i, n)
    cin >> a[i];
    stack<int>st;
    int ans[n];
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[i] <= a[st.top()])
        {
            st.pop();
        }
        if(st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() + 1;
        st.push(i);
    }
    rep(i,n)
    cout<<ans[i]<<" ";
    return 0;
}

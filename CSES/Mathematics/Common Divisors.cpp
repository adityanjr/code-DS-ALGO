// Maximum pair GCD
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
const int maxn = 1e6 + 5;
int c[maxn];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    rep(i, n)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    for(int i=maxn-1;i;--i)
    {
        int d=0;
        for(int j=i;j<maxn;j+=i)
        {
            d+=c[j];
        }
        if(d>1)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
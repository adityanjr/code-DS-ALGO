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
#define trav(a,x) for(auto & a : x);
array<int, 2>med {-1};
set<array<int, 2>>bot, top;
void fix()
{
    int m = 1 + bot.size() + top.size();//total size
    if(bot.size() < (m - 1) / 2)
    {
        bot.insert(med);
        med = *top.begin();
        top.erase(med);
    }
    if(bot.size() > (m - 1) / 2)
    {
        top.insert(med);
        med = *--bot.end();
        bot.erase(med);
    }
}
void add(array<int, 2>x)
{
    if(med[0] == -1)
    {
        med = x;
        return;
    }
    if(x < med)
        bot.insert(x);
    else
        top.insert(x);
    fix();
}
void rem(array<int, 2>x)
{
    if(x == med)
    {
        med = *top.begin();
        top.erase(med);
    }
    else if(x < med)
    {
        bot.erase(x);
    }
    else
        top.erase(x);
    fix();
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n)
    cin >> a[i];
    if(k == 1)
    {
        rep(i, n)
        cout << a[i] << ' ';
        exit(0);
    }
    rep(i, k - 1)
    {
        add({a[i], i});
    }
    for(int i = k - 1; i < n; i++)
    {
        add({a[i], i});
        cout << med[0] << ' ';
        rem({a[i - k + 1], i - k + 1});
    }
    return 0;
}
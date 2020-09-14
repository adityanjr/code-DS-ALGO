// Sum in the range [a,b]
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 2e5 + 5;
ll ft[maxn];
int n;
void modify(int x, ll v)
{
    for(; x < n; x |= (x + 1))
        ft[x] += v;
}
ll get(int x)
{
    ll res = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        res += ft[x];
    return res;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    ll x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        modify(i, x);
    }
    for(int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << get(v - 1) - get(u - 2) << '\n';
    }
}

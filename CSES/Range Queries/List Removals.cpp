// Remove the kth element from a list and print the list for each query.
// Binary Lifting.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
class fenwick
{
public:
    vector<T> fenw;
    ll n;
    fenwick(ll _n) : n(_n)
    {
        fenw.resize(n + 1);
    }
    void modify(ll x, T v)
    {
        x++;
        while (x <= n)
        {
            fenw[x] += v;
            x += (x & -x);
        }
    }
    T get(ll x)
    {
        T v{};
        x++;
        while (x > 0)
        {
            v += fenw[x];
            x -= (x & -x);
        }
        return v;
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll>a(n);
    fenwick<int>ft(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ft.modify(i, 1);
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int sum{}, h{};
        for(int l = 20; l >= 0; l--)
        {
            if(h + (1 << l) < n && sum + ft.fenw[h + (1 << l)] <x)
            {
                h += (1 << l);
                sum += ft.fenw[h];
            }
        }
        cout << a[h] << ' ';
        ft.modify(h, -1);
    }
}
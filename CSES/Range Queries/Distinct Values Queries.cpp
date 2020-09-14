// Maximum Distinct Subarray without updates
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(),x.end()
struct segtree
{
    struct node
    {
        ll sum = 0;
        ll add = 0;
        ll mn = 0;
        ll xr = 0;
        ll mx = 0;
        void apply(int l, int r, ll v)
        {
            sum += (r - l + 1) * v;
            add += v;
            mn += v;
            mx += v;
            xr += v;
        }
    };
    int n;
    vector<node>tree;
    node unite(const node &a, const node &b)
    {
        node res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        res.xr = (a.xr ^ b.xr);
        return res;
    }
    void push(int x, int l, int r)
    {
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        if(tree[x].add != 0)
        {
            tree[x + 1].apply(l, m, tree[x].add);
            tree[y].apply(m + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }
    void pull(int x, int y)
    {
        tree[x] = unite(tree[x + 1], tree[y]);
    }
    void build(int x, int l, int r, const vector<ll> &v)
    {
        if(l == r)
        {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        build(x + 1, l, m, v);
        build(y, m + 1, r, v);
        pull(x, y);
    }
    node get(int x, int l, int r, int ql, int qr)
    {
        if(ql <= l && r <= qr)
            return tree[x];
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        node res;
        if(qr <= m)
            res = get(x + 1, l, m, ql, qr);
        else if (ql > m)
            res = get(y, m + 1, r, ql, qr);
        else
            res = unite(get(x + 1, l, m, ql, qr), get(y, m + 1, r, ql, qr));
        pull(x, y);
        return res;
    }
    void modify(int x, int l, int r, int ql, int qr, const ll &v)
    {
        if(ql <= l && r <= qr)
        {
            tree[x].apply(l, r, v);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        if(ql <= m)
            modify(x + 1, l, m, ql, qr, v);
        if(qr > m)
            modify(y, m + 1, r, ql, qr, v);
        pull(x, y);
    }
    segtree(const vector<ll> &v)
    {
        n = v.size();
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    segtree(const int &_n)
    {
        n = _n;
        tree.resize(2 * n - 1);
    }
    void modify(int l, int r, const ll &v)
    {
        modify(0, 0, n - 1, l, r, v);
    }
    node get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    }
};
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>>queries[n];
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b, a--, b--;
        queries[b].push_back({a, i});
    }
    map<int, int>mp;
    segtree st(n);
    ll ans[n];
    for(int i = 0; i < n; i++)
    {
        st.modify(i, i, 1);
        if(mp.find(a[i]) != mp.end())
        {
            st.modify(mp[a[i]], mp[a[i]], -1);
        }
        mp[a[i]] = i;
        for(auto it : queries[i])
        {
            ans[it.second] = st.get(it.first, i).sum;
        }
    }
    for(int i = 0; i < q ; i++)
        cout << ans[i] << ' ';
}
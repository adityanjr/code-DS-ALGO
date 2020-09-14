// Maximum sum subarray and updates.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
struct segtree
{
    struct node
    {
        ll sum = 0;
        ll add = 0;
        ll pref = 0;
        ll suf = 0;
        ll ans = 0;
        void apply(int l, int r, const ll &v)
        {
            sum = v;
            pref = suf = ans = max(v, 0ll);
        }
    };
    int n;
    vector<node>tree;
    node unite(const node &a, const node &b)
    {
        node res;
        res.sum = a.sum + b.sum;
        res.pref = max(a.sum + b.pref, a.pref);
        res.suf = max(b.sum + a.suf, b.suf);
        res.ans = max({a.ans, b.ans, a.suf + b.pref});
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
    vector<ll>a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    segtree st(a);
    for(int i = 0; i < q; i++)
    {
        ll u, v;
        cin >> u >> v, u--;
        st.modify(u, u, v);
        cout << st.get(0, n - 1).ans << '\n';
    }
 
}
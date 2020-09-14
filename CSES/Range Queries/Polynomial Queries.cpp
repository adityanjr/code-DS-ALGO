// Update the subarray [a,b] by series 1,2,..,b-a+1 and get sum.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
struct segtree
{
    struct node
    {
        ll sum = 0;
        ll add1 = 0;
        ll add2 = 0;
        void apply(int l, int r, const ll &v1, const ll &v2)
        {
            sum += v1 * (r - l + 1);
            sum += v2 * ((ll)r * (r + 1) / 2 - (ll)l * (l - 1) / 2);
            add1 += v1;
            add2 += v2;
        }
    };
    int n;
    vector<node>tree;
    node unite(const node &a, const node &b)
    {
        node res;
        res.sum = a.sum + b.sum;
        return res;
    }
    void push(int x, int l, int r)
    {
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        tree[x + 1].apply(l, m, tree[x].add1, tree[x].add2);
        tree[y].apply(m + 1, r, tree[x].add1, tree[x].add2);
        tree[x].add1 = 0ll;
        tree[x].add2 = 0ll;
    }
    void pull(int x, int y)
    {
        tree[x] = unite(tree[x + 1], tree[y]);
    }
    void build(int x, int l, int r, const vector<ll> &v)
    {
        if(l == r)
        {
            tree[x].sum = v[l];
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
    void modify(int x, int l, int r, int ql, int qr, const ll &v1, const ll &v2)
    {
        if(ql <= l && r <= qr)
        {
            tree[x].apply(l, r, v1, v2);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        if(ql <= m)
            modify(x + 1, l, m, ql, qr, v1, v2);
        if(qr > m)
            modify(y, m + 1, r, ql, qr, v1, v2);
        pull(x, y);
    }
    segtree(const vector<ll> &v)
    {
        n = v.size();
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    void modify(int l, int r, const ll &v1, const ll &v2)
    {
        modify(0, 0, n - 1, l, r, v1, v2);
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
    {
        cin >> a[i];
    }
    segtree st(a);
    for(int i = 0; i < q; i++)
    {
        int t;
        ll a, b;
        cin >> t >> a >> b, a--, b--;
        if(t == 1)
        {
            st.modify(a, b, (ll)(1ll - a), 1ll);
        }
        else
        {
            cout << st.get(a, b).sum << '\n';
        }
    }
}
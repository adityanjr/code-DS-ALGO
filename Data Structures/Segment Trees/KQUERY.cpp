/*
 *  Author: Tara Prasad	
 *  Problem: http://www.spoj.com/problems/KQUERY/
 */
#include <bits/stdc++.h>
#define DEBUG
#ifdef DEBUG
	#include "printcpp11.h" 
#endif
using namespace std;

#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define REV_ALL(x) x.rbegin(), x.rend()
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
#define endl '\n'
#define what_is(x) cout << #x << " = " << x << endl
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, st, ed, inc) for(ll i = st; i < ed; i += inc)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = numeric_limits<ll>::max();
const ll NINF = numeric_limits<ll>::min();
const ll M = 1E9 + 7;
const double EPS = 1E-9;

struct query {
	int l, r, k, index;
	query(int ll, int rr, int kk, int id) {
		l = ll; r = rr; k = kk; index = id;
	}
};

int n, q; 
vii a;
vi ans;
vector<query> queries;

vi s; 
void build(int id = 1, int l = 0, int r = n){
	if(r == l + 1){
		s[id] = 1; // initially set to 1 -> i.e. all numbers are greater than k
		return;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	s[id] = s[2 * id] + s[2 * id + 1];
}

// make the value at position p -> 0.
void update(int p, int id = 1, int l = 0, int r = n){
	if(r == l + 1){
		s[id] = 0;
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, 2 * id, l, mid);
	else
		update(p, 2 * id + 1, mid, r);
	s[id] = s[2 * id] + s[2 * id + 1];
}

int sum(int x, int y, int id = 1, int l = 0, int r = n){// [x, y)
	if(x >= r or l >= y) return 0;	// [x, y) intersection [l,r) = empty
	if(x <= l && r <= y)			// [l,r) is a subset of [x,y)
		return s[id];
	int mid = (l + r)/2;
	return sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r);
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	a.resize(n);
	FOR(i, 0, n, 1) {
		cin >> a[i].F;
		a[i].S = i;
	}
	cin >> q;
	queries.assign(q, query(0, 0, 0, 0));
	FOR(i, 0, q, 1) {
		int l, r, k;
		cin >> l >> r >> k;
		queries[i] = query(l - 1, r, k, i);
	}
	sort(ALL(a));
	// sort according to k
	sort(ALL(queries), [](query a, query b) -> bool {
		return a.k < b.k;
	});

	s.resize(4 * (n + 1));
	build(); // mark element in segment tree 1
	ans.resize(q);

	int pos = 0;
	// overalll O(n) as the pos increments n times
 	FOR(i, 0, q, 1) {
		// mark elements till queries[i].k as 0, meaning they are less than k
.		while(pos < n && a[pos].F <= queries[i].k) {
			update(a[pos].S); // actual index
			pos++;
		}
		ans[queries[i].index] = sum(queries[i].l, queries[i].r);
	}

	FOR(i, 0, q, 1) {
		cout << ans[i] << "\n";
	}
	return 0;
}

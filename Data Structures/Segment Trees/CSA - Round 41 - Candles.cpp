/*
 *  Author: Tara Prasad 
 */
#include <bits/stdc++.h>
// #include "printcpp11.h"
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
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, s, e) for(ll i = s; i < e; i++)
#define leftmost_set(x) __builtin_clzll(x)
#define CASET int ___T, case_n = 1; cin >> ___T; while (___T--)
#define wi(x) what_is(x)
#define what_is(x) cerr << #x << " = " << x << endl;
#define LCHILD(n) (2 * n)
#define RCHILD(n) (2 * n + 1)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = 1E9;
const ll NINF = -1E9;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const double PI = 2 * acos(0);

void get_arr(vi& a, int n) {
	a.resize(n); for(int i = 0; i < n; i++) cin >> a[i];
}

void print_arr(const vi &a) {
	for(int i = 0; i < SZ(a); i++) {cout << a[i] << " ";} cout << endl;
}

const int MAXN = 1E5 + 5;

struct node {
	int lazy = 0; // updates to be propagated to the children
	int mx = NINF; // maximum height of the candle present in the range denoted by the node
	node() {}
};

ostream& operator <<(ostream& outputStream, const node& p){
	outputStream << p.mx; 
	return outputStream;
}

struct segment_tree {
	// in all the functions range [l, r] are both left and right inclusive
	int n; vector<node> s;
	vector<int> a; // for debugging
	segment_tree(vector<int>& candle_heights) {
		n = SZ(candle_heights);
		s.assign(4 * (n + 1), node());
		a = candle_heights;
		build(1, n, 1);
	}

	// check whether its possible to have the required candles, if yes, then decrement 
	// 1 from the candles used, and keep them sorted in decreasing order
	bool can_light(int num_candles) {
		if(num_candles > n) return false;
		
		int h = get_value(num_candles); // can't use a[num_candles - 1] since need to propagate the pending lazy updates first
		if(h == 0) return false; // sufficient candles not available

		// perform binary search, can't use STL's upper_bound as lazy updates are pending
		int pos2 = get_rightmost_pos(h);
		int pos1 = get_rightmost_pos(h + 1); // should get 0 if h + 1 doesn't exist
		
		lazy_update(1, pos1, -1);
		int remaining = num_candles - pos1;
		lazy_update(pos2 - remaining + 1, pos2, -1);
		return true;
	}
    
    void lazy_update(int l, int r, int value) {
        if(l <= r) // being cautious
            lazy_update(1, n, 1, l, r, value);
    }
    
	void build(int l, int r, int node) {
		if(l == r) {
			s[node].mx = a[l - 1]; // a is 0 indexed
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, LCHILD(node));
		build(mid + 1, r, RCHILD(node));
		update_node(node);
	}

	void lazy_update(int l, int r, int node, int c1, int c2, int value) {
		if(l >= c1 && r <= c2) {
			s[node].mx += value;
			s[node].lazy += value;
			if(l == r) a[l - 1] = s[node].mx; // updating the candle heights (for debugging puposes)
			return;
		}
		if(r < c1 || l > c2) return;
		int mid = (l + r) / 2;
		lazy_update(l, mid, LCHILD(node), c1, c2, value);		
		lazy_update(mid + 1, r, RCHILD(node), c1, c2, value);
		update_node(node);
	}

	int get_value(int pos) {
		return get_value(pos, 1, n, 1);
	}

    // for all ranges [l, r] return -INF except when l = r = pos, thus value = RMQ(1, n)  
    // this is simply RMQ on this array [-INF -INF ... -INF (value to return) -INF ... -INF -INF]
	int get_value(int pos, int l, int r, int node) {
		if(pos < l || pos > r) return NINF;
		if(l == r) {
			return s[node].mx;
		}
		propagate_lazy(node);
		int mid = (l + r) / 2;
		return max(get_value(pos, l, mid, LCHILD(node)), get_value(pos, mid + 1, r, RCHILD(node)));
	}

	int get_rightmost_pos(int value) {
		if(s[1].mx < value) // value is too big, return the 0th position (sentinel) 
			return 0;
		return get_rightmost_pos(value, 1, 1, n);
	}

	int get_rightmost_pos(int value, int node, int l, int r) {
		if(l == r) return l; // found the rightmost index for the given value
		propagate_lazy(node); // there may be some pending updates
		
		int mid = (l+r) / 2;
		if(s[RCHILD(node)].mx >= value) { 	// this is just like the ok() function in binary search
			return get_rightmost_pos(value, RCHILD(node), mid + 1, r);
		} else {
			return get_rightmost_pos(value, LCHILD(node), l, mid);
		}
	}

	void propagate_lazy(int node) {
		s[LCHILD(node)].lazy += s[node].lazy; // to update the grand children
		s[RCHILD(node)].lazy += s[node].lazy; // to update the grand children
		s[LCHILD(node)].mx += s[node].lazy; // lazy updation, maximum gotta increase while range increment
		s[RCHILD(node)].mx += s[node].lazy;
		s[node].lazy = 0; // nothing else to propagate further
	}

	// get the latest value of the node from its children
	void update_node(int node) {
		propagate_lazy(node); // ensure that the children have the latest values
		s[node].mx = max(s[LCHILD(node)].mx, s[RCHILD(node)].mx); 
	}
};

int main() {
	IO_SPEED_UP;
	if(fopen("tupni.txt", "r")) {
		freopen("tupni.txt", "r", stdin); 
		freopen("tuptuo.txt", "w", stdout);
	}
	int n, m; cin >> n >> m;
	vector<int> candles(n);
	for(int i = 0; i < n; i++) {
		cin >> candles[i];
	}
	sort(REV_ALL(candles));
	segment_tree tree(candles);
	for(int i = 0; i < m; i++) {
		int num_candles; cin >> num_candles;
		if(not tree.can_light(num_candles)) {
			cout << i << "\n";
			return 0;
		} 
	}
	cout << m << "\n"; // all could be lit!
}
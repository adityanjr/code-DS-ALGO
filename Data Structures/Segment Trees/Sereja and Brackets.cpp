/*
 *  Author: Tara Prasad	
 * 	Problem: http://codeforces.com/contest/380/problem/C
 */
#include <bits/stdc++.h>
// #define DEBUG
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
#define ALL1(x) x.begin() + 1, x.end()
#define REV_ALL1(x) x.rbegin(), x.rend() - 1
#define SZ(x) (int)x.size()
#define CONTAINS(cont, val) (cont.find(val) != cont.end())
#define endl '\n'
#define what_is(x) cout << #x << " = " << x << endl
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR1(i, n) for(ll i = 1; i <= n; i++)
#define FOR(i, n) for(ll i = 0; i < n; i++)
#define REV_FOR(i, n) for(ll i = n - 1; i >= 0; i--)
#define REV_FOR1(i, n) for(ll i = n; i >= 1; i--)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = numeric_limits<ll>::max();
const ll NINF = numeric_limits<ll>::min();
const ll M = 1E9 + 7;
const double EPS = 1E-9;

struct node {
	int ans, open, closed;
	node(int x, int y, int z) {
		ans = x;
		open = y;
		closed = z;
	}
};

ostream& operator <<(ostream& outputStream, const node& p){
	outputStream << "(" << p.ans <<", " << p.open << ", "  << p.closed << ")"; 
	return outputStream;
}

string str; int n;
vector<node> nodes;
void build(int id = 1,int l = 0, int r = n){
	if(l + 1 == r){
		if(str[l] == '(') {
			nodes[id].open = 1;
		} else {
			nodes[id].closed = 1;
		}
		return;
	}
	
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);

	int to_add = min(nodes[2*id].open, nodes[2*id + 1].closed);
	nodes[id].ans = nodes[2*id].ans + nodes[2*id + 1].ans + to_add;
	nodes[id].open = nodes[2*id].open + nodes[2*id + 1].open - to_add;
	nodes[id].closed = nodes[2*id].closed + nodes[2*id + 1].closed - to_add;
}

node count(int x, int y, int id = 1, int l = 0, int r = n) {
	if(l >= r || r <= x || l >= y) return node(0, 0, 0);
	if(l >= x && r <= y) {
		return nodes[id];
	}
	int mid = (l+r)/2;
	node left = count(x, y, 2*id, l, mid);
	node right = count(x, y, 2*id + 1, mid, r);

	int to_add = min(left.open, right.closed);
	int ans = left.ans + right.ans + to_add;
	int open = left.open + right.open - to_add;
	int closed = left.closed + right.closed - to_add;
	return node(ans, open, closed);
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> str; n = SZ(str);
	nodes.assign(4 * (n + 1), node(0, 0, 0));
	build();

	// what_is(nodes);
	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r; l--;
		cout << count(l, r).ans * 2 << "\n"; // since in the seg tree, ((())) is counted as 3.
	}
	return 0;
}
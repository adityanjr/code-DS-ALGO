/*
 *  Author: Tara Prasad	
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

int n, q;
vi a, s; 
void build(int id = 1, int l = 0, int r = n){
	//what_is(mt(id, l, r));
	if(r == l + 1){
		s[id] = a[l];
		//what_is(ii(id, s[id])); 
		return;
	}
	int mid = (l+r)/2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	int distance = log2(r - l);
	if(distance % 2 == 1) {
		s[id] = s[2 * id] | s[2 * id + 1];
	} else {
		s[id] = s[2 * id] ^ s[2 * id + 1];
	}
	//what_is(ii(id,s[id]));
}

void update(int p, int v, int id = 1, int l = 0, int r = n){
	// what_is(mt(id, l, r));
	if(r == l + 1){
		s[id] = v;
		// what_is(ii(id, s[id]));
		return ;
	}
	int mid = (l+r)/2;
	if(p < mid)
		update(p, v, 2 * id, l, mid);
	else
		update(p, v, 2 * id + 1, mid, r);
	int distance = log2(r - l);
	if(distance % 2 == 1) {
		s[id] = s[2 * id] | s[2 * id + 1];
	} else {
		s[id] = s[2 * id] ^ s[2 * id + 1];
	}
	// what_is(ii(id, s[id]));
}

int main() {
	IO_SPEED_UP;
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> q;
	n = 1 << n;
	a.resize(n); 
	FOR(i, 0, n, 1) {
		cin >> a[i];
	}
	// what_is(n);
	s.resize(4* (n + 1));
	build();
	//what_is(s);
	while(q--) {
		int p, b; cin >> p >> b;
		update(p - 1, b);
		cout << s[1] << "\n";
	}
	return 0;
}
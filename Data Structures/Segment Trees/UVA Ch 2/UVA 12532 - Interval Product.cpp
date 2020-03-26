/*
 *  Author: Tara Prasad
 *  Problem: 12532
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
#define leftmost_set(x) __builtin_clzll(x)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = 1E9;
const ll NINF = -1E9;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const int N = 1E5 + 5;

int n;
vi a, s;

#define LEFT(i) (i << 1)
#define RIGHT(i) ((i << 1) + 1)

inline int convert(int x) {
  if(x == 0) return 0;
  if(x > 0) return 1;
  return -1;
}

void build(int id = 1, int l = 0, int r = n){
  if(l + 1 == r){  //  l + 1 == r
    s[id] = a[l];
    return;
  }
  int mid = (l+r)/2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid, r);
  s[id] = s[id * 2] * s[id * 2 + 1];
}

void modify(int p, int x, int id = 1, int l = 0, int r = n){
  if(p < l || p >= r)  return; // saved from TLE
  if(l + 1 == r){ //  l = r - 1 = p
    if(l == p)
      s[id] = x;
    return;
  }
  int mid = (l + r)/2;
  modify(p, x, id * 2, l, mid);
  modify(p, x, id * 2 + 1, mid, r);
  s[id] = s[2 * id] * s[2 * id + 1]; // rebuild the whole affected tree
}

int product(int x, int y, int id = 1, int l = 0, int r = n){
  if(x >= r or l >= y)  return 1;
  if(x <= l && r <= y)  return s[id];
  int mid = (l+r)/2;
  return product(x, y, id * 2, l, mid) *
  product(x, y, id * 2 + 1, mid, r);
}

inline void print_result(int v) {
  if(v > 0) cout << "+";
  else if(v < 0) cout << "-";
  else cout << 0;
}

int main() { 
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int k;
  while(cin >> n >> k) {
    s.clear();
    a.resize(n);
    s.assign(4*n, 1);

    for(int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = convert(a[i]);
    }
    build();
    for(int i = 0; i < k; i++) {
      char type; cin >> type;
      if(type == 'C') {
        int k, v; cin >> k >> v;
        v = convert(v);
        modify(k - 1, v);
      } else {
        int l, r; cin >> l >> r;
        print_result(product(l - 1, r));
      }
    }
    cout << "\n";
  }
  return 0;
}

/*
 *  Author: Tara Prasad
 *  Problem: 11402 - Ahoy Pirates
 */
#include <bits/stdc++.h>
//#define DEBUG
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
const int N = 1024005;

int n;
int lazy[4*(N+1)], s[4*(N+1)], a[N];
/*
  LAZY = {0, 1, 2, 3}
  0 = DO NOTHING
  1 = SET
  2 = CLEAR
  3 = FLIP
*/
void build(int id = 1, int l = 0, int r = n){
  if(l + 1 == r){  //  l + 1 == r
    s[id] = a[l];
    return;
  }
  int mid = (l+r)/2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid, r);
  s[id] = s[id * 2] + s[id * 2 + 1];
}

// for a flip operation
int new_lazy_value(int v) {
  if(v == 2) return 1;
  if(v == 1) return 2; 
  if(v == 3) return 0; // flip of flip
  if(v == 0) return 3; // flip on nothing
}

void upd(int id, int l, int r, int x){ // increase all members in this interval by x
  if(x == 0) return; // do not set the lazy value in this case
  // previous lazy value is retained
  if(x != 3) lazy[id] = x;
  if(x == 1)
    s[id] = (r - l);
  else if(x == 2)
    s[id] = 0;
  else if(x == 3) {
    lazy[id] = new_lazy_value(lazy[id]);
    s[id] = (r - l) - s[id]; // flip
  }
  // what_is(mt("upd", id, l, r, s[id]));
}

void shift(int id, int l, int r){ // pass update information to the childrenw
  // what_is(mt("shift", id, l, r));
  int mid = (l+r)/2;
  upd(id * 2, l, mid, lazy[id]);
  upd(id * 2 + 1, mid, r, lazy[id]);
  lazy[id] = 0; // passing is done, do nothing
}

void update(int x, int y, int v, int id = 1, int l = 0, int r = n){
  // what_is(mt("update", x, y, v, id, l, r));
  if(x >= r or l >= y)  return ;
  if(x <= l && r <= y){
    upd(id, l, r, v);
    return;
  }
  shift(id, l, r);
  int mid = (l + r)/2;
  update(x, y, v, id * 2, l, mid);
  update(x, y, v, id*2+1, mid, r);
  s[id] = s[id * 2] + s[id * 2 + 1];
}

// to obtain the sum of the query 
int sum(int x, int y, int id = 1, int l = 0, int r = n){
  if(x >= r or l >= y)  return 0;
  if(x <= l && r <= y)  return s[id];
  shift(id, l, r);
  int mid = (l + r)/2;
  return sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r);
}

void print_arr(int a[], int n) {
  cout << "[";
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  int case_t = 1;
  while(t--) {
    cout << "Case " << case_t++ << ":" << "\n";
    n = 0;
    memset(lazy, 0, sizeof(lazy));
    memset(s, 0, sizeof(s));
    memset(a, 0, sizeof(a));
    int m; cin >> m;
    int ind = 0;
    for(int i = 0; i < m; i++) {
      int x; cin >> x;
      string s; cin >> s;
      for(int i = 0; i < x; i++) {
        for(int j = 0; j < SZ(s); j++) {
          a[ind++] = s[j] - '0'; 
        }
      }
    }
    n = ind;
    // what_is(n);
    build();
    // print_arr(s, 4 * (n + 1));
    int q; cin >> q;
    int case_q = 1;
    while(q--){
      char type; int l, r;
      cin >> type >> l >> r; r++;
      // what_is(type);
      if(type == 'F') {
        update(l, r, 1);
      } else if(type == 'E') {
        update(l, r, 2);
      } else if(type == 'I') {
        update(l, r, 3);
      } else {
        cout << "Q" << case_q++ << ": ";
        cout << sum(l, r) << "\n";
      }
      // print_arr(s, 4 * n + 4);
    }
  }
  return 0;
}

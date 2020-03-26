/*
 *  Author: Tara Prasad
 *  Problem: 12086
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
const int N = 200005;

int n;
vi a, s;
void build(int id = 1, int l = 0, int r = n){
  if(l + 1 == r){ //  l + 1 == r
    s[id] = a[l];
    return ;
  }
  int mid = (l+r)/2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid, r);
  s[id] = s[id * 2] + s[id * 2 + 1];
}

void modify(int p, int x, int id = 1, int l = 0, int r = n){
  if(p < l || p >= r)  return; 
  if(l + 1 == r){ //  l = r - 1 = p
    if(l == p)
      s[id] = x; 
    return;
  }
  int mid = (l + r)/2;
  // make both the calls, and rebuild the entire table
  modify(p, x, id * 2, l, mid);
  modify(p, x, id * 2 + 1, mid, r);
  s[id] = s[2 * id] + s[2 * id + 1]; 
}

int sum(int x, int y, int id = 1, int l = 0, int r = n){
  if(x >= r or l >= y)  return 0;
  if(x <= l && r <= y)  return s[id];
  int mid = (l+r)/2;
  return sum(x, y, id * 2, l, mid) +
  sum(x, y, id * 2 + 1, mid, r);
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  for(int tt = 1; ; tt++) {
    cin >> n;
    if(n == 0) break;
    if(tt != 1) cout << "\n";
    cout << "Case " << tt << ":" << "\n";
    
    a.resize(n);
    s.assign(4 * n, 0);
    
    for(int i = 0; i < n; i++) cin >> a[i];
      build();

    while(1) {
      string type; cin >> type;
      if(type == "END") break;
      int x, y; cin >> x >> y;
      if(type == "M") {
        cout << sum(x-1, y) << endl;
      } else {
        modify(x-1, y);
      }
    }
  }
  return 0;
}

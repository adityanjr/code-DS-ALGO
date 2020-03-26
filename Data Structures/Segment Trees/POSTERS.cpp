/*
 *  Author: Tara Prasad
 *  Problem: www.spoj.com/problems/POSTERS/
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
const int N = 40005;

int n;
vi lazy;
void shift(int id) {
  if(lazy[id]) 
    lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
  lazy[id] = 0;
}

void paint(int x, int y, int color, int id = 1, int l = 0,int r = n){
  if(x >= r or l >= y)  return ;
  if(x <= l && r <= y){
    lazy[id] = color;
    return ;
  }
  int mid = (l+r)/2;
  shift(id);
  paint(x, y, color, 2 * id, l, mid);
  paint(x, y, color, 2*id+1, mid, r);
}

set<int> ans;
void cnt(int id = 1,int l = 0, int r = n){
  if(lazy[id]){
    ans.insert(lazy[id]);
    return ; // there is no need to see the children, because all the interval is from the same color
  }
  if(r == l + 1) return ;
  int mid = (l+r)/2;
  cnt(2 * id, l, mid);
  cnt(2*id+1, mid, r);
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while(t--) {
    ans.clear();
    int x; cin >> x;
    set<int> pts;
    vii ranges(x);
    for(int i = 0; i < x; i++) {
      int l, r; cin >> l >> r;
      pts.insert(l);
      pts.insert(r);
      ranges[i] = mp(l, r);
    }
    int k = 0;
    map<int, int> m;
    for(auto p: pts) {
      m[p] = k++;
    }
    n = k;
    for(int i = 0; i < x; i++) {
      ranges[i].F = m[ranges[i].F];
      ranges[i].S = m[ranges[i].S];
    }
    lazy.assign(4 * (k + 1), 0);
    for(int i = 0; i < x; i++) {
      paint(ranges[i].F, ranges[i].S + 1, i + 1);
    }
    cnt();
    cout << ans.size() << "\n";
  }
  return 0;
}

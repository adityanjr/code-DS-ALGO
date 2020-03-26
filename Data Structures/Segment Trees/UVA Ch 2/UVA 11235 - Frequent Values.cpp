/*
 *  Author: Tara Prasad
 *  Problem: 11235
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
#define leftmost_set(x) __builtin_clzll(x)

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = 1E9;
const ll NINF = -1E9;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const int N = 100005;

class RMQ { // Range Maximum Query
private:
  int n;
  vi A; // copy of the input array
  vvi SpT; // SpT[i][j] stores the index of the minimum element starting 
  // at index i and ending at index i + 2^j - 1
public:
  RMQ(vi& a) {
    n = a.size();
    A.resize(n);
    int max_log2 = floor(log((double)n)/log(2.0)) + 1;
    SpT.assign(n, vi(max_log2));
    for (int i = 0; i < n; i++) {
      A[i] = a[i];
      SpT[i][0] = i; // RMQ of sub array starting at index i and length 2^0
    }
    for (int j = 1; (1 << j) <= n; j++) {// for each j s.t. 2^j <= n, O(log n)
      for (int i = 0; i + (1 << j) - 1 < n; i++) {// for each valid i, O(n)
        // RMQ: from two overlapping ranges whose union covers the interval [i, i + 2^j - 1]
        if (A[SpT[i][j - 1]] > A[SpT[i + (1 << (j - 1))][j - 1]]) 
          SpT[i][j] = SpT[i][j - 1]; // start at index i of length 2 ^ (j - 1)
        else // start at index i + 2 ^ (j - 1) of length 2 ^ (j - 1)
          SpT[i][j] = SpT[i + (1 << (j - 1))][j-1];
      }
    }
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j - i + 1) / log(2.0)); // 2^k <= (j-i+1)
    // RMQ: from two overlapping ranges R1, R2 whose union covers the interval [i, j]
    // R1 = the first 2^k elements, R2 = the last 2^k elements
    if (A[SpT[i][k]] >= A[SpT[j - (1 << k) + 1][k]]) 
      return SpT[i][k];
    else 
      return SpT[j - (1 << k) + 1][k];
  } 
};

vi start, finish;

vi pre_process(vi &a) {
  int n = SZ(a); vi cnt(n);
  start.resize(n); finish.resize(n);
  start[0] = 0; finish[n - 1] = n - 1;
  for(int i = 1; i < n; i++) {
    if(a[i] == a[i - 1]) 
      start[i] = start[i - 1];
    else 
      start[i] = i;
  }
  for(int i = n - 2; i >= 0; i--) {
    if(a[i] == a[i + 1]) 
      finish[i] = finish[i + 1];
    else
      finish[i] = i;
  }
  for(int i = 0; i < n; i++) {
    int length = finish[i] - start[i] + 1;
    cnt[i] = length;
  }
  return cnt;
}

int query(int l, int r, vi &a, vi &cnt, RMQ &rmq) {
  if(l > r) return -1;
  int n = SZ(a);
  if(a[l] == a[r]) return r - l + 1;
  if((l == 0 || a[l] != a[l - 1]) && (r == n - 1 || a[r + 1] != a[r])) {
    return cnt[rmq.query(l, r)];
  }
  int k1 = query(l, finish[l], a, cnt, rmq);
  int k2 = query(finish[l] + 1, start[r] - 1, a, cnt, rmq);
  int k3 = query(start[r], r, a, cnt, rmq);
  return max(k1, max(k2, k3));
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  while(1) {
    int n, q; cin >> n;
    if(n == 0) break;
    cin >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vi cnt = pre_process(a);
    RMQ rmq(cnt);

    while(q--) {
      int l, r; cin >> l >> r;
      l--; r--;
      cout << query(l, r, a, cnt, rmq) << "\n";
    }
  }
  return 0;
}

/*
 *  Author: Tara Prasad
 *  Problem: 
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
const ll M = 1E9 + 7; // for prime M only
const double EPS = 1E-9;
const int N = 1005; 
const int R = 805;

// if N = 1E6, don't use dp, use ncr formula directly 

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll mod_inverse(ll x) {
    return modpow(x, M - 2, M); // from Euler's 
}

int dp[N][R];
int ncr(int n, int r) {
  if(n < r) return 0;
  if(n == r || n <= 0 || r <= 0) return 1;
  if(dp[n][r] != -1) return dp[n][r];

  ll x = ((ll)n * (ll)ncr(n - 1, r - 1)) % M;
  x *= mod_inverse(r);
  x %= M;
  dp[n][r] = x;
  return x;
}

int main() {
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while(t--) {
    memset(dp, -1, sizeof(dp));
    int n, r; cin >> n >> r;
    cout << ncr(n, r) << "\n";
  }
  return 0;
}

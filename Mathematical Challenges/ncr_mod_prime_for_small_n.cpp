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
#define what_is(x) cout << #x << " = " << x << endl
#define IO_SPEED_UP ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, s, e) for(ll i = s; i < e; i++)
#define leftmost_set(x) __builtin_clzll(x)
#define Heap priority_queue

typedef long long ll;typedef pair<ll, ll> ii;
typedef vector<ll> vi;typedef vector<bool> vb;
typedef vector<ii> vii;typedef vector<vi> vvi;

const ll PINF = 1E9;
const ll NINF = -1E9;
const ll M = 1E9 + 7;
const double EPS = 1E-9;
const double PI = 2 * acos(0);

vi get_arr(int n) {
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i]; return a;
}

void print_arr(const vi &a) {
    for(int i = 0; i < SZ(a); i++) cout << a[i] << " "; cout << endl;
}

ll modpow(ll n, ll e, ll m) {
    ll res = 1;
    n %= m;
    while(e) {
        if(e & 1) {
            res *= n;
            res %= M;
        }
        e = e >> 1;
        n *= n;
        n %= M;
    }
    return res;
}

ll mod_inverse(ll x, ll m) {
    return modpow(x, m - 2, m); // from Euler's 
}
vi fact;
ll mod_ncr(ll n, ll r, ll m) {
    ll deno = (mod_inverse(fact[n-r], m) * mod_inverse(fact[r], m)) % m;
    return (fact[n] * deno) % m;
}

void calc_fact(int n, int m) {
    fact.assign(n + 1, 1);
    for(int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= m; 
    }
}

int main() {
    std::ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    calc_fact(1E6, M);
    what_is(mod_ncr(15, 4, M));
    return 0;
}

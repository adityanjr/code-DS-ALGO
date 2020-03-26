#include <bits/stdc++.h>
#include "printcpp11.h"
using namespace std;
const int epsilon = 1E-12;
const int INF = 1000000000;
#define DEBUG

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
typedef long long ll;
typedef vector<int> vi;

template <typename T>
T power(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll mod_inverse(ll x, ll M) {
    return power(x, M - 2, M); // from Euler's 
}

vi fact;

// mod with a prime number
ll ncr_mod(ll n, ll r, ll M) {
    ll deno = (mod_inverse(fact[n - r], M) * mod_inverse(fact[r], M)) % M;
    return (fact[n] * deno) % M;
}

ll lucas_rec(ll n, ll r, ll M) {
    if(r == 0) return 1;
    ll n_last_bit = n % M;
    ll r_last_bit = r % M;
    if(r_last_bit > n_last_bit) return 0;
    ll ret = (lucas_rec(n/M, r/M, M) * ncr_mod(n_last_bit, r_last_bit, M)) % M;
    return ret;
}

void compute_factorials(int M) {
    fact.assign(M + 1, 1);
    FOR(i, 2, M + 1) {
        fact[i] = (fact[i - 1] % M * i % M) % M;
    }
}

int main() {
	std::ios::sync_with_stdio(false);
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    compute_factorials(1E6 + 3);
	int t;
	cin >> t;
	while(t--) {
	    ll n, r, m; cin >> n >> r >> m;
	    cout << lucas_rec(n, r, m) << endl;
	}
	return 0;
}

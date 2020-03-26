/*
 *  Author: Tara Prasad
 *  Problem: 297
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

vvi image;
string s;
int id;

void paint(int r, int c, int w) {
  char x = s[id++];
  // what_is(mt(r, c, w, x));
  if(x == 'p') {
    paint(r, c + w/2, w/2);
    paint(r, c, w/2);
    paint(r + w/2, c, w/2);
    paint(r + w/2, c + w/2, w/2);
  } else if(x == 'f'){
    for(int i = r; i < r + w; i++) {
      for(int j = c; j < c + w; j++) {
        image[i][j] = 1;
      }
    }
  }
}

int main() { 
  IO_SPEED_UP;
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while(t--) {
    image.assign(32, vi(32, 0));
    id = 0;
    cin >> s;
    paint(0, 0, 32);

    id = 0;
    cin >> s;
    paint(0, 0, 32);

    int cnt = 0;
    for(int i = 0; i < 32; i++) {
      for(int j = 0; j < 32; j++) {
        cnt += image[i][j];
      }
    }
    cout << "There are " << cnt << " black pixels." << "\n";
  }
  return 0;
}


/*
problem: http://codeforces.com/contest/837/problem/D
*/
 
#include<bits/stdc++.h> //g++ -std=c++11
using namespace std;
 
//#define DEBUG
#ifndef DEBUG
  #define din if(0) cin
  #define dout if(0) cout
#else
  #define din cin
  #define dout cout
#endif
 
 
#define inf (1 << 30)
#define pi (2*asin(1))
#define repall(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define rep(i,x,y) for (int i = x; i < y; i++)
#define irep(i,x,y) for (int i = x; i >= y; i--)
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mp make_pair
#define MAX 5205
 
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long int i64;
typedef vector < i64 > vi64;
int dp[2][205][MAX];
int n, k, two[205], five[205];
int totFive = 0 ;
void toNum(i64 x, int i){
  two[i] = five[i] = 0;
  while(x % 2ll == 0){
    two[i]++;
    x /= 2ll;
  }
  while(x % 5ll == 0){
    five[i]++;
    x /= 5ll;
  }
  totFive += five[i];
}
int main()
{
  scanf("%d %d", &n, &k);
  rep(i, 0, n){
    i64 x;
    cin >> x;
    toNum(x, i);
  }
  rep(j, 0, k + 1) rep(l, 0, totFive + 1) dp[0][j][l] = dp[1][j][l] = -inf;
  dp[0][0][0] = dp[1][0][0] = 0;
  rep(num, 0, n){
    int i = (num % 2);
    int i_n = i xor 1;
 
    rep(j, 0, k + 1){
      rep(l, 0, totFive + 1){
        dp[i_n][j][l] = dp[i][j][l];
        if (l - five[num] >= 0 && j > 0)
          dp[i_n][j][l] = max(dp[i_n][j][l], dp[i][j - 1][l - five[num]] + two[num]);
      }
    }
  }
  int ans = 0;
  rep(l, 0, totFive + 1) ans = max(ans, min(l, dp[n%2][k][l]));
  printf("%d\n", ans);
}


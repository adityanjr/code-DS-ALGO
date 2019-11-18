#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
const int D = 100;
void inputVec(vi&v) {for (auto&i : v)cin >> i;}
void printVec(vi&v) {for (auto&i : v)cout << i << " "; cout << endl;}
void printMat(vvi& mat) {for (auto&v : mat) {for (auto&x : v)cout << x << " ";} cout << endl;}
/********************************/

int matrixMul(vi& v, int be, int en) {
    if (be >= en) {
        return 0;
    }

    if (be + 1 == en ) {
        return 0;
    }

    int ans = inf;
    for (int i = be + 1; i < en; ++i) {
        int q1 = matrixMul(v, be, i);
        int q2 = matrixMul(v, i, en);
        int q3 = v[be] * v[i] * v[en];
        int totalOper = q1 + q2 + q3;
        ans = min(ans, totalOper);
    }
    return ans;
}

int matrixMul(vi& v) {
    int n = v.size();
    int dp[D][D] = {};

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len - 1; ++i) {
            int srt = i;
            int end = srt + len;
            for (int k = 1; k <= len - 1; ++k) {
                int q1 = dp[srt][srt + k];
                int q2 = dp[srt + k][end];
                int q3 = v[srt] * v[i] * v[end];
                int total = q1 + q2 + q3;
                dp[srt][end] = min(dp[srt][end], total);
            }
        }
    }
    return dp[0][n - 1];
}


int main() {
    int n; cin >> n;
    vi v(n);
    inputVec(v);
    printVec(v);
    int ans = matrixMul(v);
    cout << ans;
}
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(x) cout <<#x<<": "<<x<<'\n';

const int N = 100005;

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> sum;
        int a[n + 1];
        for (i = 0; i < n; i++) {
            cin >> a[i + 1];
        }
        int dp[n + 1][sum + 1] = {};
        dp[0][0] = 1;
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - a[i] >= 0) {
                    dp[i][j] |= dp[i - 1][j - a[i]];
                }
            }
        }
        cout << (dp[n][sum] ? "Yes" : "No");
    }
}
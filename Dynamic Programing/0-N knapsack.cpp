#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

const int N = 100005;

int32_t main()
{
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        int size[n + 1], value[n + 1];
        for (i = 1; i <= n; i++) {
            cin >> size[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> value[i];
        }
        int dp[n + 1][m + 1] = {};
        for (i = 1; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                if (j - size[i] >= 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - size[i]] + value[i]);
                    dp[i][j] = max(dp[i][j], dp[i][j - size[i]] + value[i]);
                    if (j > 0) {
                        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                    }
                }
            }
        }
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<'\n';
        // }
        cout << dp[n][m];
    }
}
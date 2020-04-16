//  https://www.interviewbit.com/problems/distinct-subsequences/

int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    
    if(m>n)
        return 0;
    
    int dp[n+1][m+1];
    
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
        
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(A[i-1]!=B[j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    /*
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    return dp[n][m];
}


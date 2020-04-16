//  https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    
    int n = A.size();
    int m = B.size();
    
    if(m+n != C.size())
        return false;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 && j==0)
                dp[i][j] = true;
            else if(i==0 && B[j-1]==C[j-1])
                dp[i][j] = dp[i][j-1];
            else if(j==0 && A[i-1]==C[i-1])
                dp[i][j] = dp[i-1][j];
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                dp[i][j] = dp[i-1][j];
            else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                dp[i][j] = dp[i][j-1];
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }
    return dp[n][m];
}


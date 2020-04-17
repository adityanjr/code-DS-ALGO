//  https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    
    for(int i=0;i<n;i++)
        if(A[i][0]!=1)
            dp[i][0] = 1;
        else 
            break;
    
    for(int j=0;j<m;j++)
        if(A[0][j]!=1)
            dp[0][j] = 1;
        else 
            break;
            
    for(int i=1;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(A[i][j]!=1)
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    /*
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
    return dp[n-1][m-1];
}


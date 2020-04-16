//  https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int> > &A) {

    int n = A.size();
    int m = A[0].size();
    
    int dp[n][m];
    
    dp[n-1][m-1] = (A[n-1][m-1]>=0)?0:abs(A[n-1][m-1]);
    
    for(int i=n-2;i>=0;i--) {
        int ans = dp[i+1][m-1] - A[i][m-1];
        dp[i][m-1] = (ans>0)?ans:0;
    }
    
    for(int j=m-2;j>=0;j--) {
        int ans = dp[n-1][j+1] - A[n-1][j];
        dp[n-1][j] = (ans>0)?ans:0;
    }
    
    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--) {
            int ans = min(dp[i+1][j], dp[i][j+1]) - A[i][j];
            dp[i][j] = (ans>0)?ans:0;
        }
    }
    /*
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }
    */
    return dp[0][0]+1;
}



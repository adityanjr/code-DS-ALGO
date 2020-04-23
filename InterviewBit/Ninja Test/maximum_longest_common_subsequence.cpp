void LCS(string A, string B, vector<int> &ans) {
    int n = A.size();
    int m = B.size();
    
    int dp[n+1][m+1];   // 2D vector to store LCS value, dp[i][j] stores LCS of first i character of A and first j characters of B
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(A[i-1]==B[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    // find out the maximal value and the corresponding index by traversing the 2D vector.
    // Traversal is done either from the first charcter of A and last character of B, or from last character of A and first character of B.
    for(int i=1,j=n;i<=n;j--,i++) {
        if(ans[1] < dp[i][j]) { // When the current maximal value exceeds the stored maximal value, update the stored value.
            ans[1] = dp[i][j];
            ans[0] = i;
        }
    }
    
}
vector<int> Solution::maxLCS(string A) {
    // to store answer
    vector<int> ans(2);
    ans[0] = 1; // stores j value for maximal LCS
    ans[1] = 0; // stores maximal LCS value
    
    string B = A;
    reverse(B.begin(), B.end());
    B.pop_back();   // trim last character of the reversed string
    A.pop_back();   // trim last character of the original string
    
    /*
    
    Let's say we have "abbc" as A.
    We have to calcute LCS for the following combinations.
    A | B
    ------
    a   bbc
    ab  bc
    abb c
    
    You can notice that last character in the first column i.e. 'c' and first character in the 2nd column i.e. 'a' are of no use.
    That's why, they have been trimmed earlier from A and B respectively.
    
    */
    
    LCS(A, B, ans); // calculate LCS
    
    
    return ans;
}

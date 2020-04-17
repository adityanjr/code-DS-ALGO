//  https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int Solution::numTrees(int A) {
    
    int dp[A+1];

    dp[0] = dp[1] = 1;
    
    for(int i=2;i<=A;i++) {
        int ci = 0;
        for(int j=0;j<i;j++)
            ci += dp[j]*dp[i-j-1];
        dp[i] = ci;
    }
    /*
    for(int i=0;i<=A;i++)
        cout << dp[i] << " ";
    cout << endl;
    */
    return dp[A];
}


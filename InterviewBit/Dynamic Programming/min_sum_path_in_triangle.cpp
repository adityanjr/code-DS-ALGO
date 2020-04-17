//  https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int N = A.size();
    
    if(N==0)
        return 0;
    
    int **dp = new int*[N];
    for(int i=0;i<N;i++)
        dp[i] = new int[i+1];
        
    dp[0][0] = A[0][0];
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0)
                dp[i][j] = dp[i-1][j] + A[i][j];
            else if(j==i) {
                dp[i][j] = dp[i-1][j-1] + A[i][j];
            }
            else {
                dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    /*
    for(int i=0;i<N;i++) {
        for(int j=0;j<=i;j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }
    */
    int ans = INT_MAX;
    
    for(int i=0;i<N;i++)
        ans = min(ans, dp[N-1][i]);
    return ans;
}


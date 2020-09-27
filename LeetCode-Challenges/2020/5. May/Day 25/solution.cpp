class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[A.size()+1][B.size()+1];
        dp[0][0]=0;
        for(int i=1;i<=A.size();i++)
        {
            dp[i][0]=0;
        }
        for(int j=1;j<=B.size();j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=A.size();i++)
        {
            for(int j=1;j<=B.size();j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};
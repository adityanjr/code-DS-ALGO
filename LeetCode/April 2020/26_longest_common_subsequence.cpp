class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int nr,nc;
        nr = text1.length();
        nc = text2.length();
        
        if(text1.compare(text2) == 0){
            return text1.length();
        }
        
        vector<vector<int>> dp(nr+1,vector<int>(nc+1));
        text1 = " "+text1;
        text2 = " "+text2;
        
        
        for(int i = 0;i<nc+1;i++){
            dp[0][i] = 0;
        }
        for(int i = 0;i<nr+1;i++){
            dp[i][0]= 0;
        }
        
        
        // i - text1 | j - text2
        
        //Iterative dp
        for(int i = 1;i<nr+1;i++){
            for(int j=1;j<nc+1;j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[nr][nc];
    }
};
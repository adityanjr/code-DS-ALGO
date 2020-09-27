class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans[word1.size()+1][word2.size()+2];
        ans[0][0]=0;
        for(int i=1;i<=word1.size();i++)
            ans[i][0]=i;
        
        for(int i=1;i<=word2.size();i++)
            ans[0][i]=i;
        
        for(int i=1;i<=word1.size();i++)
            for(int j=1;j<=word2.size();j++)
                if(word1[i-1]==word2[j-1])
                    ans[i][j]=ans[i-1][j-1];
                else
                    ans[i][j]=1+min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1]));
        
        return ans[word1.size()][word2.size()];
    }
};
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector <vector<int>> ans;
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                vector<int> val;
                int Max=max(A[i][0],B[j][0]);
                int Min=min(A[i][1],B[j][1]);
                if(Min>=Max)
                {
                    val.push_back(Max);
                    val.push_back(Min);
                    ans.push_back(val);
                }
                
            }
        }
        return ans;
    }
};
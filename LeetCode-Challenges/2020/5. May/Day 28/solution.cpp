class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=num;i++)
        {
            ans.push_back(ans[i>>1]+i%2);
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int array_size = static_cast<int>(nums.size());
        if(!array_size){
            return 0;
        }
        vector<int>dp(array_size , 1);
        for(int i=0; i<array_size; ++i){
            for(int j=0; j<i;++j){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[j]+1 , dp[i]);
            }
        }
        return *max_element(dp.begin() , dp.end());
    }
};

/*
   This problem was asked by Facebook.

 Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

 For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, since we can't split it up into two subsets that add up to the same sum.

 *
 */
class Solution {
    unordered_map<int,bool>dp;
    bool dfs(vector<int>&n , int index , int target){
        if(dp.find(target)!=dp.end()){
            return dp[target];
        }
        if(index>=n.size() or target<0)return false;
        dp[target] = false;
        for(auto i=index;i<(int)n.size(); ++i){
            if(dfs(n , i+1 , target - n[i])){
                dp[target] = true;
                return dp[target];
            }
        }
        return dp[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum%2 or nums.size() == 1){
            return false;
        }else if(nums.size()==0){
            return true;
        }
        sort(nums.begin() , nums.end());
        dp[0] = true;
        return dfs(nums , 0 , sum/2);
    }
};

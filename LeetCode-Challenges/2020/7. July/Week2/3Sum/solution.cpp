class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        
        if(n < 3) return ans;
        
        for(int i = 0; i < n - 2; ++i) {
            int curr = nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while(left < right) {
                int csum = curr + nums[left] + nums[right];
                
                if(csum == 0) {
                    s.insert({curr, nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if(csum < 0) {
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    left++;
                } else {
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    right--;
                }
            }
            
        }
        
        for(auto x: s){
            ans.push_back(x);
        }
        
        return ans;
    }
};
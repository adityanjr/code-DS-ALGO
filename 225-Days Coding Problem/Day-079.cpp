class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int counter{};
        const int n = static_cast<int>(nums.size());
        for (int i = 0; i < n-1; ++i) {
            if(nums[i] > nums[i+1] && counter) {
                return false;
            }
            if(nums[i] > nums[i+1]) {
                if( i>0 && nums[i+1] < nums[i-1] ) {
                    nums[i+1] = nums[i];
                }else{
                    nums[i] = nums[i+1];
                }
                ++counter;
            }
        }
        return true;
    }
};


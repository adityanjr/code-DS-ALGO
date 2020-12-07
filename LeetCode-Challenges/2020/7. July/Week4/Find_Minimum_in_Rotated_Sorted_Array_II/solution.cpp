class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        if(nums.size() == 1) return nums[0];
        if(nums[high] > nums[low]) return nums[0];
        
        while(low < high) {
            mid = low + (high - low) / 2;
            
            if(nums[mid] == nums[high]) {
                high--;
            } else if(nums[mid] < nums[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return nums[low];
    }
};
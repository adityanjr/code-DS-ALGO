class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int last = (int)nums.size()-2;
        while(last >= 0 && nums[last] >= nums[last+1]){
            last--;
        }
         if(last < 0){
             sort(nums.begin() , nums.end());
             return;
         }
        for(int i=nums.size()-1;i>last;--i){
            if(nums[i] > nums[last]){
                swap(nums[i] , nums[last]);
                break;
            }
        }
        reverse(nums.begin()+last+1 , nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = (int)nums.size();
        int one=0,zero=0, two=n-1;
        while(one <= two){
            if(nums[one] == 2 && one < two){
                swap(nums[two] , nums[one]);
                --two;
            }else if(nums[one] == 0 && one > zero){
                swap(nums[zero] , nums[one]);
                ++zero;
            }else{
                ++one;
            }
        }
    }
};

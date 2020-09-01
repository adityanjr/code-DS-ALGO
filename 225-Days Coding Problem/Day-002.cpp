class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const size_t n= nums.size();
        vector<int>ans(n,1);
        int answer =1;
        for(size_t i=0;i<n; ++i){
            if(i==0){
                ans[i] = nums[i];
            }else{
                ans[i] = nums[i]*ans[i-1];
            }
        }
        int temp;
        for(int i=n-1;i>=0;--i){
            if(i!=0){
                temp = nums[i];
                nums[i] = ans[i-1]*answer;
                answer*=temp;
            }else{
                nums[i] = answer;
            }
        }
        return nums;
    }
};

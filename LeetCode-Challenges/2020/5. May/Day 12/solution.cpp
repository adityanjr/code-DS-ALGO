class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size()==1)
        {
            return nums[0];
        }
       long l=0;
        if(nums[l]<nums[l+1])
        {
            return nums[l];
        }
        long r=nums.size()-1;
        if(nums[r]>nums[r-1])
        {
            return nums[r];
        }
        long mid=(l+r)/2;
        while(r-l>=0)
        {
            if(mid<nums.size()-1 && mid>0 && nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1] )
            {
                return nums[mid];
            }
            if(mid<nums.size()-1 && (mid%2==0 &&  nums[mid]==nums[mid+1])||(mid%2!=0 && nums[mid]!=nums[mid+1]))
            {
                l=mid-1;
                mid=(l+r)/2;

            }
            else
            {
                r=mid+1;
                mid=(l+r)/2;
            }
        }
        return -1;
    }
};

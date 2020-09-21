class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i])==hash.end())
            {
                hash[nums[i]]=1;
            }
            else
            {
                hash[nums[i]]++;
            }
        }
        int Max=0,max_val;
        for(int i=0;i<nums.size();i++)
        {

                if(hash[nums[i]]>Max)
                {
                    Max=hash[nums[i]];
                    max_val=nums[i];
                }

        }
        return max_val;
    }
};

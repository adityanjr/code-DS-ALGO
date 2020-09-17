class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxg = nums[0];
        int maxc = maxg;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            maxc = max(nums[i], maxc + nums[i]);
            if (maxc > maxg)
                maxg = maxc;
        }
        return maxg;
    }
};
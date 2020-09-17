class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        int n = nums.size();
        for (int x : nums)
        {
            if (x != 0)
            {
                nums[j++] = x;
            }
        }
        while (j < n)
            nums[j++] = 0;
    }
};
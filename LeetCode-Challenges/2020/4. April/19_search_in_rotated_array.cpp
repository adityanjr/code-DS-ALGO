class Solution
{

public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();

        if (n == 0)
        {
            return -1;
        }

        if (n == 1)
        {
            if (target == nums[0])
            {
                return 0;
            }
            return -1;
        }

        int low = 0, high = n - 1;

        int mid = 0;

        while (low <= high)
        {
            mid = (low + high) / 2;
            int val = nums[mid];
            if (val == target)
            {
                return mid;
            }
            if (nums[low] <= val)
            {
                if (target < val && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (target > val && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
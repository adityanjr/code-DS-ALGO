class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return true;
        }

        pair<int, int> span = {0, 0};
        int maxsp = 0;
        while (true)
        {
            for (int i = span.first; i <= span.second; ++i)
            {
                maxsp = max(maxsp, i + nums[i]);
            }
            if (maxsp <= span.second)
            {
                return false;
            }
            if (maxsp >= n - 1)
            {
                return true;
            }
            span.first = span.second + 1;
            span.second = maxsp;
        }
        return false;
    }
};
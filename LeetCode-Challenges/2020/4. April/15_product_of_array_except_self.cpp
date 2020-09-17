class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int zc = 0;
        for (int x : nums)
        {
            if (x == 0)
            {
                zc++;
            }
        }
        vector<int> result;
        if (zc == 0)
        {
            int p = 1;
            for (int x : nums)
            {
                p *= x;
            }

            for (int x : nums)
            {
                result.emplace_back(p / x);
            }
        }
        else if (zc == 1)
        {
            int p = 1;
            for (int x : nums)
            {
                if (x != 0)
                {
                    p *= x;
                }
            }

            for (int x : nums)
            {
                if (x != 0)
                {
                    result.emplace_back(0);
                }
                else
                {
                    result.emplace_back(p);
                }
            }
        }
        else
        {
            for (int x : nums)
            {
                result.emplace_back(0);
            }
        }
        return result;
    }
};
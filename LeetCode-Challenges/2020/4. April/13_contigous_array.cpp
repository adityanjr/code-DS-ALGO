class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        vector<int> p;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        p.emplace_back(0);
        for (int x : nums)
        {
            p.emplace_back(p.back() + x);
        }

        map<int, vector<int>> m;
        int ps = p.size();
        for (int i = 0; i < ps; ++i)
        {
            m[p[i]].emplace_back(i);
        }

        int diff = 0;

        for (auto v : m)
        {
            int y = *(v.second).rbegin();
            int x = v.second[0];
            int d = y - x;
            if (d > diff)
            {
                diff = d;
            }
        }
        return diff;
    }
};
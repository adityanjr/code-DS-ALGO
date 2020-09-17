class Solution
{
public:
    int countElements(vector<int> &arr)
    {
        unordered_map<int, int> m;
        for (int x : arr)
        {
            m[x] = 0;
        }
        for (int x : arr)
        {
            for (int y : arr)
            {
                if (x + 1 == y)
                {
                    m[x]++;
                    break;
                }
            }
        }
        int sum = 0;
        for (auto p : m)
        {
            if (p.second != 0)
                sum += p.second;
        }
        return sum;
    }
};
class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int b = -1, s = 0;
        int profit = 0;
        int n = p.size();
        for (int i = 1; i < n; ++i)
        {
            if (b == -1)
            {
                if (p[i] > p[i - 1])
                {
                    b = i - 1;
                    s = i;
                }
            }
            else
            {
                if (p[i] > p[i - 1])
                    s = i;
                else if (p[i] < p[i - 1])
                {
                    profit += p[s] - p[b];
                    b = -1;
                }
            }
            if (i == (n - 1) && b != -1)
                profit += p[n - 1] - p[b];
        }
        return profit;
    }
};
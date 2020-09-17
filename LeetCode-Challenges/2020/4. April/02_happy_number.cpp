class Solution
{
public:
    int createSum(int n)
    {
        int sum = 0;
        while (n)
        {
            int r = n % 10;
            n /= 10;
            sum += (r * r);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> visited;
        while (1)
        {
            n = createSum(n);
            if (visited.count(n) == 1)
            {
                return false;
            }
            visited.insert(n);
            if (n == 1)
                return true;
        }
    }
};
class Solution
{

public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> q;

        for (int x : stones)
        {
            q.push(x);
        }

        while (q.size() > 1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if (x != y)
            {
                q.push(y - x);
            }
        }

        if (!q.empty())
        {
            return q.top();
        }
        return 0;
    }
};